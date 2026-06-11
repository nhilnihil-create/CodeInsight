#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    const double pi = 3.1415926535898;
    double r;
    cin >> r;
    cout << fixed << setprecision(6) << r*r*pi << " " << pi*r*2 << endl;
    return 0;
}
