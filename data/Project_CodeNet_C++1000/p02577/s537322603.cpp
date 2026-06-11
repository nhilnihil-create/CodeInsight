#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string n;
    std::cin >> n;
    int sum = 0;
    for (char c : n) {
        int i = c - '0';
        sum += i;
    }
    if (sum % 9 == 0) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
}