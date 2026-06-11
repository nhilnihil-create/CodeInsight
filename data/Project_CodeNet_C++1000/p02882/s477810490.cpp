#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, x; cin >> a >> b >> x;
    double p, theta;
    if(x*2 < a*a*b){
        p = 2*x/(a*b);
        theta = atan(b/p);
    }else{
        p = 2*(b - (x/(a*a)));
        theta = atan(p/a);
    }
    const double pi = acos(-1);
    cout << fixed << setprecision(10) << 180 * theta / pi << endl;
    return 0;
}