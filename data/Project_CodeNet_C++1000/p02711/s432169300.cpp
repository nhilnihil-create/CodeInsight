#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    bool result = false;
    while (num != 0)
    {
        int digit = num % 10;
        if (result = digit == 7)
            break;
        num /= 10;
    }

    if (result)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}