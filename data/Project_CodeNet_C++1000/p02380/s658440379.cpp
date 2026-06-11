#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int    a, b;
    double c;
    int    C;

    cin >> a >> b >> C;
    
    double S = (1.0 / 2.0) * a * b * sin(C * (double)M_PI / 180.0);
    
    c = (double)sqrt(a * a + b * b - 2 * a * b * (cos(C * (double)M_PI / 180.0)));

    double L = a + b + c;

    double h = 2.0 * S / a;

    cout << fixed << setprecision(13) << S << " " << setprecision(13) << L << " " 
                  << setprecision(13) << h << endl;
   
    return (0);
}