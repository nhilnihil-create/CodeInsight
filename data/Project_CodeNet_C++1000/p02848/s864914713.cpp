#include <iostream>
using namespace std;

char resChar(char c, int i) {
    int j = (c - 'A' + i) % 26;
    char d = 'A' + j;
    return d;
}

int main(void) {
    int n;
    std::string s;

    std::cin >> n;
    std::cin >> s;

    for(char c : s) {
        char d = resChar(c, n);
        std::cout << d;
    }

    std::cout << std::endl;

    return 0;
}
