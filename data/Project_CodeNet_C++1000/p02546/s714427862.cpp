#include <iostream>
#include <string>

int main () {

    std::string s;
    std::cin >> s;

    if(s.back() == 's') std::cout << s + "es" << std::endl;
    else std::cout << s + "s" << std::endl;

    return 0;
}