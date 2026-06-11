#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    while (x != 0) {
        if (x % 10 == 7)
        {
            std::cout << "Yes";

            return 0;
        }
        x /= 10;
    }
    std::cout << "No";
}