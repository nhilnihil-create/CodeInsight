#include<iostream>
using namespace std;
#include<iomanip>

#define _USE_MATH_DEFINES
#include<cmath>

int main()
{
    double r, S, l;
    cin >> r;
 
    S = M_PI * r * r;
    l = 2 * M_PI * r;
    cout << fixed << setprecision(10) << S << " " << l << endl;
  
    return 0;
}