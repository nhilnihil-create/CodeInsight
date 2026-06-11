#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double r;
    double pi = 3.141592653589;
    cin >> r;
    double S = pi*r*r;
    double R = 2 * pi*r;
    cout << fixed << setprecision(5) << S << " " << fixed << setprecision(5) << R << endl;

    return 0;
}