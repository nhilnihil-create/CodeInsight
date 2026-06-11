#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
        double a, b ,C;
        cin >>a >> b >>C;
        double C_r = C * M_PI /180;
        double c = pow( (pow(a,2)+pow(b,2)-(2.0*a*b*cos(C_r))),0.5);
        double S = (a * b * sin(C_r)) /2;
        double L = a + b + c;
        double h = S / a * 2;
        cout << fixed << S <<" "<< L<< " "<< h  <<endl;

        return 0;
}
