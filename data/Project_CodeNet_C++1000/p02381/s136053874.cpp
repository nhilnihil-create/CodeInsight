#include <iostream>
#include <vector>
#include <cmath>


int main()
{
    while (true) {
        int students_num;
        std::cin >> students_num;

        if (students_num == 0) {
            break;
        }

        std::vector<int> points(students_num);
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