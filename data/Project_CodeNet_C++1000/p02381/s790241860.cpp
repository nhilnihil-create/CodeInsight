#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    while (true) {
        std::size_t n;
        std::cin >> n;
        if (n == 0) {
            break;
        }

        int score[n];
        int sum = 0;
        for (std::size_t i = 0; i < n; ++i) {
            std::cin >> score[i];
            sum += score[i];
        }

        double average = (double)(sum) / n;

        double v = 0.0;
        for (std::size_t i = 0; i < n; ++i) {
            v += (score[i] - average) * (score[i] - average);
        }

        double sd = sqrt(v/n);

        std::cout << std::fixed << std::setprecision(20) << sd << std::endl;
    }


    return 0;
}
