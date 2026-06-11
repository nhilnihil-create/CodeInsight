#include <iostream>
#include <string>

std::string s;
std::string t;
std::string u;

int a;
int b;

int main() {
    std::cin >> s >> t;
    std::cin >> a >> b;
    std::cin >> u;

    if (s==u) {
        a -= 1;
    } else {
        b -= 1;
    }
    std::cout << a << ' ' << b << std::endl;
}