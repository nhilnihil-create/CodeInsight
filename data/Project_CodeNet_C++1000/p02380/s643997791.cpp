#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265359
using namespace std;

int main(){
    double x,y,angle;
    double area,surround,high;
    cin >> x >> y >> angle;
    area = 0.5 * x * y * sin(PI * angle/180);
    surround = x + y + sqrt( (x*x + y*y) -2*x*y*cos(PI * angle/180) );
    high = y * sin(PI * angle/180);

    cout << fixed << setprecision(10) << area << endl;
    cout << fixed << setprecision(10) << surround << endl;
    cout << fixed << setprecision(10) << high << endl;

    return 0;
}