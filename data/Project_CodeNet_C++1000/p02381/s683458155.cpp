#include <iostream>
#include <iomanip> //setprecision
#include <cstdlib>
#include <vector>
#include <cmath>

int main(void) {
    double number;
    std::vector<double> v(1000);
    std::cin >> number;
    double sum;
    double average;
    double dispersion;
    while(number != 0) {
        sum = 0;
        dispersion = 0.0;
        for (double i = 0; i < number; i++) {
            std::cin >> v[i];
            sum += v[i];
        }
        average = sum / number;
        for (int i = 0; i < number; i++) {
            dispersion += (average - v[i]) * (average - v[i]);
        }
        dispersion /= number;
        std::cout << std::fixed << std::setprecision(12);
        std::cout << sqrt(dispersion) << std::endl;
    std::cin >> number;
    }
    return EXIT_SUCCESS;
}