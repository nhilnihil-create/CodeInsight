#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    const double Pi=3.14159265358979;
    double r;
    cin >> r;
 
    double s=Pi*r*r;
    double l=2*Pi*r;
 
    cout << fixed << setprecision(6) << s << " " << l << endl;
    return 0;
}