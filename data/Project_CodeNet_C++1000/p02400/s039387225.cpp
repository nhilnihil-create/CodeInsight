#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double r; 
    cin >> r;
    
    cout << fixed << setprecision(5);
    cout << M_PI * r * r << ' ' << 2.0 * M_PI * r << endl;
    
    return 0;
}
