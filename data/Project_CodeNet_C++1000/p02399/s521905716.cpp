#include<iostream>
using namespace std;
#include<iomanip>
   
int main()
{
    int a, b, r, d;
    double f;
    cin >> a >> b;
 
    d = a / b;
    r = a % b;
    f = (a * 1.0) / b;
    cout << d << " " << r << " " << fixed << setprecision(10) << f << endl;
 
    return 0;
}