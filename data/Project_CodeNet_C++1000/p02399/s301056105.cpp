#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long   a, b;
    long   d;
    long   r;
    double f;

    do {
        cin >> a >> b;
    } while ((a < 1 || a > 1000000000) || (b < 1 || b > 1000000000));

    d = a / b;
    r = a % b;
    f = (double)a / b;
 
    cout << fixed << d << " " << r << " " << setprecision(8) << f << endl;
   
    return (0);
}