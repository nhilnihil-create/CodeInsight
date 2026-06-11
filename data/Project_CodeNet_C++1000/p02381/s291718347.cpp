#include <iostream>
#include <array>
#include <cmath>

constexpr int MAX = 1000;

int main()
{
    while (true) {
        int students_num;
        std::cin >> students_num;

        if (students_num == 0) {
            break;
        }

        std::array <int, MAX> points;
        for (int i = 0; i < students_num; i++) {
            std::cin >> points.at(i);
        }

        double ave = 0;
        for (int i = 0; i < students_num; i++) {
            ave += points.at(i);
        }
        ave /= students_num;

        double variance = 0;
        for (int i = 0; i < students_num; i++) {
            variance += pow(points.at(i) - ave, 2);
        }
        variance /= students_num;

        double deviation = sqrt(variance);

        std::cout << std::fixed << deviation << std::endl;
    }

    return 0;
}