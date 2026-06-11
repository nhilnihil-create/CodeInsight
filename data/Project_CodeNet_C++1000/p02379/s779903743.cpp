#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, dist;
    cin >> x1 >> y1 >> x2 >> y2;
    printf("%lf\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

    return 0;
}

