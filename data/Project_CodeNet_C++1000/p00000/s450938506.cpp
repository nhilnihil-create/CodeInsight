#include <iostream>
#include <string>

int main()
{
    std::string str;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            str = str + std::to_string(i) + "x" + std::to_string(j) + "=" + std::to_string(i * j) + "\n";
        }
    }
    std::cout << str;
    return 0;
}