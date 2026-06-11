#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    int a, b, C;
    cin >> a >> b >> C;
    double theta;
    theta = C * M_PI / 180;

    double S, L, h;
    S = a * b * sin(theta) / 2;
    //cout << S << endl;
    printf("%.4f\n", S);
    
    double c;
    c = sqrt(a * a + b * b - 2 * a * b * cos(theta));
    L = a + b + c;
    //cout << L << endl;
    printf("%.4f\n", L);

    h = S / a * 2;
    //cout << h << endl;
    printf("%.4f\n", h);
    
	return 0;
}

