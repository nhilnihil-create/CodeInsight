#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
double PI = acos(-1);

int main(){
    double a, b, c, deg, rad;
    double area, circum, height;
    cin >> a >> b >> deg;
    rad = 2 * PI * deg / 360;
    c = sqrt(a * a + b * b - 2 * a * b * cos(rad));
    
    area = 0.5 * a * b * sin(rad);
    circum = a + b + c;
    height = b * sin(rad);

    cout << setprecision(10) << area << endl;
    cout << setprecision(10) << circum << endl;
    cout << setprecision(10) << height << endl;


    return 0;
}
