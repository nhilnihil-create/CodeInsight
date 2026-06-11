#include <iostream>
#include <cmath>
using namespace std;
double to_rad(int deg){
    return deg * M_PI / 180.0;
}
  
int main(void){
    int a,b,d;
    cin >> a >> b >> d;

    double S = (a * b * sin(to_rad(d)) / 2);
    double c = sqrt(pow(a,2) - 2*a*b*cos(to_rad(d)) + pow(b,2));
    double L = a + b + c;
    double h = 2 * S / a;
    cout << fixed << S << endl;
    cout << fixed << L << endl;
    cout << fixed << h << endl;
}