#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long long int a, b;
    int d, r;
    double f;
    
    cin  >> a >> b;
    
    d = a / b;
    r = a % b;
    f = static_cast<double>(a) / b;
    
    cout << d << " " << r << " " 
         << fixed << showpoint << setprecision(5)
         << f << endl;

    return 0;
}