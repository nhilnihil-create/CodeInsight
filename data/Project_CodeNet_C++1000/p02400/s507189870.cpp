#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double PI = 3.14159265359;
    double r, a, b;
    
    cin  >> r;
    a = r * r * PI;
    b = 2 * r * PI;
    
    cout << fixed << showpoint << setprecision(6)
         << a << " " << b << endl;

    return 0;
}