#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    double r;
    cin >> r;
    cout.precision(6);
    cout << fixed << r * r * M_PI << " " << fixed << 2 * M_PI * r << endl;

    return 0;
}