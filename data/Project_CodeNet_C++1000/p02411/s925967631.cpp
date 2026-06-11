#include <iostream>

int main()
{
    while (1) {

        int m,f,r;

        std::cin >> m >> f >> r;
        
        if (m == -1 && f == -1 && r == -1) {
            break;
        }
        if (m == -1 || f == -1) {
            std::cout << "F" << std::endl;
        } else if (m + f < 30) {
            std::cout << "F" << std::endl;
        } else if (m + f < 50 && r >= 50) {
            std::cout << "C" << std::endl;
        } else if (m + f < 50) {
            std::cout << "D" << std::endl;
        } else if (m + f < 65) {
            std::cout << "C" << std::endl;
        } else if (m + f < 80) {
            std::cout << "B" << std::endl;
        } else {
            std::cout << "A" << std::endl;
        }

    }

    return 0;
}