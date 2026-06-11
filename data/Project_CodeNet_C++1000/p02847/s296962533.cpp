#include <iostream>
#include <string>

std::string s;
int days;

int main() {
    std::cin >> s;
    if (s == "SUN") {
        days = 7;
    }
    else if (s == "MON") {
        days = 6;
    } else if (s == "TUE") {
        days = 5;
    } else if (s == "WED") {
        days = 4;
    } else if (s == "THU") {
        days = 3;
    } else if (s == "FRI") {
        days = 2;
    } else if (s == "SAT") {
        days = 1;
    } else {
        days = 0;
    }
    std::cout << days << std::endl;
}