#include <iostream>
#include <string>

int main() {
    int n;
    std::string str, res = "No";
    std::cin >> n >> str;

    if(n % 2 == 0) {
        int h = n/2;

        if(str.substr(0, h) == str.substr(h)) {
            res = "Yes";
        }
    }

    std::cout << res << "\n";
}