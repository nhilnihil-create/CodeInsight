#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

double calcDistanceBetween(int sourceX, int sourceY, int targetX, int targetY) {
    const unsigned int diffX = std::abs(targetX - sourceX);
    const unsigned int diffY = std::abs(targetY - sourceY);
    return std::sqrt(diffX * diffX + diffY * diffY);
}

int main() {


    const int N_MAX = 8; // the upper bound of the N;

    int N; // the number of towns
    std::cin >> N;

    int x[N_MAX]; // stores the x coordinate for each town
    int y[N_MAX]; // stores the y coordinate for each town

    for (int i=0; i<N; ++i) {
        std::cin >> x[i] >> y[i];
    }

    double sum = 0.; // is the sum of the distance for each pair of the towns.

    for (int i=0; i<N; ++i) { // from the i-th town
        for (int j=i; j<N; ++j) { // to the j-th town
            sum += calcDistanceBetween(x[i], y[i], x[j], y[j]);
        }
    }

    sum *= 2;
    const double average = sum / N;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << average << std::endl;

    return 0;

}
