#include <iostream>

int main()
{
    int distance, time, speed;
    std::cin >> distance >> time >> speed;

    if (distance <= time * speed)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}