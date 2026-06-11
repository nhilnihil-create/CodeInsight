#define PI 3.14159265358979

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    double r;

    cin >> r;

    cout << setprecision(15) << r * r * PI << ' ' << 2 * r * PI << endl;

    return 0;
}