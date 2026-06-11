#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){

        double r;

        cin >> r;

        double area = pow(r,2) * M_PI;
        double circle = (r + r) * M_PI;
        cout << fixed << setprecision(6) << area << " "  <<circle << "\n";


        return 0;
}