#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double L, l, V;
    std::cin >> L;

    l = L/3.0;
    V = pow(l, 3.0);

    std::cout << std::fixed;
    std::cout << std::setprecision(7) << V;
}