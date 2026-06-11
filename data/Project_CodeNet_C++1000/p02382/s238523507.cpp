#include <iostream>
#include <iomanip> //setprecision
#include <cstdlib>
#include <vector>
#include <cmath>
const int MAX = 100000000;

double ans(double x, double y) {
    double dis;
    dis = x - y;
    if (dis < 0) {
        dis = dis * (-1.0);
    }
    return dis;
}

double calc(std::vector<double> x, std::vector<double> y, int data_num, int p) {
    double dis;
    double total = 0;
    double temp;
    for (int i = 0; i < data_num; i++) {
        temp = 1.0;
        dis = ans(x[i], y[i]);
        for (int j = 0; j < p; j++) {
            temp *= dis; 
        }
        total += temp;
    }
    return pow(total, 1.0 / p);
}

int main(void) {
    int data_num;
    std::cin >> data_num;
    std::vector<double> x(100);
    std::vector<double> y(100);
    for (int i = 0; i < data_num; i++) {
        std::cin >> x[i]; 
    }
    for (int i = 0; i < data_num; i++) {
        std::cin >> y[i]; 
    }
    std::cout << std::fixed << std::setprecision(12);
    std::cout << calc(x, y, data_num, 1) << std::endl;
    std::cout << calc(x, y, data_num, 2) << std::endl;
    std::cout << calc(x, y, data_num, 3) << std::endl;
    double dis_Max = 0;
    double dis;
    for (int loop = 0; loop < data_num; loop++) {
        dis = ans(x[loop], y[loop]);
        if (dis > dis_Max) {
            dis_Max = dis;
        }
    }
    std::cout << dis_Max << std::endl;

    return EXIT_SUCCESS;
}