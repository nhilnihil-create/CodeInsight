#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    double ret = sqrt(pow((x2-x1), 2.0)  + pow((y2-y1), 2.0 ));
    printf("%.6f\n", ret);
    return 0;
}