#include <iostream>
#include <math.h>
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);

    double x1,x2,y1,y2;
    double result;
    cin >> x1 >> y1 >> x2 >> y2;
    result = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
    printf("%.4lf", result);
}