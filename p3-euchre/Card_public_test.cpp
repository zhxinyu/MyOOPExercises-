// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <sstream>
#include "unit_test_framework.h"
#include "Card.h"

using namespace std;

// THESE TEST CASES WILL ONLY TELL YOU IF YOUR CODE COMPILES.
// YOU NEED TO WRITE YOUR OWN COMPREHENSIVE TEST CASES IN Card_tests.cpp

TEST(test_card_suit_and_rank) {
    Card two_spades = Card();
    ASSERT_EQUAL(two_spades.get_rank(), Card::RANK_TWO);
    ASSERT_EQUAL(two_spades.get_suit(), Card::SUIT_SPADES);
    
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_EQUAL(three_spades.get_rank(), Card::RANK_THREE);
    ASSERT_EQUAL(three_spades.get_suit(), Card::SUIT_SPADES);
    ASSERT_EQUAL(three_spades.get_suit(Card::SUIT_CLUBS), Card::SUIT_SPADES);
}

TEST(test_card_type) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    Card jack_spades = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card jack_clubs = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(three_spades.is_face());
    ASSERT_FALSE(three_spades.is_right_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(three_spades.is_left_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(three_spades.is_trump(Card::SUIT_CLUBS));
    ASSERT_TRUE(jack_spades.is_face());
    ASSERT_TRUE(jack_spades.is_right_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(jack_clubs.is_left_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(three_spades.is_trump(Card::SUIT_SPADES));

}

TEST(test_card_self_comparison) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(three_spades < three_spades);
    ASSERT_FALSE(three_spades > three_spades);
    ASSERT_TRUE(three_spades == three_spades);
    ASSERT_FALSE(three_spades != three_spades);
}


TEST(test_card_two_comparison) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    Card ace_clubs = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card ace_diamonds = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(three_spades < three_spades);
    ASSERT_FALSE(three_spades > three_spades);
    ASSERT_TRUE(three_spades == three_spades);
    ASSERT_FALSE(three_spades != three_spades);
    ASSERT_FALSE(three_spades > ace_clubs);
    ASSERT_FALSE(ace_diamonds < ace_clubs);
    ASSERT_TRUE(three_spades == three_spades);
    ASSERT_TRUE(three_spades != ace_clubs);
}



TEST(test_Suit_next) {
    ASSERT_EQUAL(Suit_next(Card::SUIT_CLUBS), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(Card::SUIT_SPADES), Card::SUIT_CLUBS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_HEARTS), Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_DIAMONDS), Card::SUIT_HEARTS);

}

TEST(test_Card_less_self) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(Card_less(three_spades, three_spades, Card::SUIT_CLUBS));
    ASSERT_FALSE(Card_less(three_spades, three_spades, three_spades,
                           Card::SUIT_CLUBS));
}

TEST(test_Card_less_diff) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    Card ace_clubs = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card ace_diamonds = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card jack_spades = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card jack_clubs = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    
    ASSERT_TRUE(Card_less(three_spades, ace_clubs, Card::SUIT_CLUBS));
    ASSERT_FALSE(Card_less(three_spades, ace_clubs, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(three_spades, jack_spades, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(three_spades, jack_clubs, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(three_spades, jack_spades, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(three_spades, jack_clubs, Card::SUIT_CLUBS));

    ASSERT_FALSE(Card_less(jack_clubs,three_spades , ace_clubs,
                           Card::SUIT_CLUBS));
    ASSERT_FALSE(Card_less(jack_clubs,three_spades , ace_clubs,
                           Card::SUIT_SPADES));

    

}



TEST(test_card_insertion) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ostringstream oss;
    oss << three_spades;
    ASSERT_EQUAL(oss.str(), "Three of Spades");
}

TEST_MAIN()
