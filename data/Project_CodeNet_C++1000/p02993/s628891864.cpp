#include <iostream>
// #include string
int s;
int one;
int ten;
int hund;
int thou;
bool difficult;
std::string goodbad;

int main() {
    std::cin >> s;
    one = s % 10;
    ten = (s % 100) / 10;
    hund = (s % 1000) / 100;
    thou = s / 1000;

    difficult = (one == ten) || (ten == hund) || (hund == thou);
    if (difficult) {
        goodbad = "Bad";
    } else {
        goodbad = "Good";
    }

    std::cout << goodbad;
}