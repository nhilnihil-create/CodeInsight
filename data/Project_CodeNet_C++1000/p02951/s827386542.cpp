#include <iostream>

int a;
int b;
int c;

int main() {
    std::cin >> a >> b >> c ;
    int out;
    if (a - b > c) {
        out = 0;
    } else {
        out = c - (a - b);
    }
    std::cout << out;
}