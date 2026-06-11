#include <iostream>
#include <utility>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
        pair<double, double> p1, p2;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        printf("%.8f\n", sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2)));
}