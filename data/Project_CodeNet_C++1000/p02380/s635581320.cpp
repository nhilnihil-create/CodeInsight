#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    int a,b,deg;
    double rad;
    double PI = acos(-1);
    cin >> a >> b >> deg;
    rad = deg * PI /180;
    cout << fixed;
    cout << setprecision(5) << a*b*sin(rad)/2 << endl;
    cout << setprecision(5) << a+b+sqrt(a*a+b*b-2*a*b*cos(rad)) << endl;
    cout << setprecision(5) << b*sin(rad) << endl;
    return 0;
}

