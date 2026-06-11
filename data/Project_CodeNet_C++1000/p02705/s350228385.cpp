#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void){
    int r;
    const double PI=3.1415926535897932;
    cin >> r;
    cout << fixed << setprecision(10) << 2 * r * PI << endl;
    return 0;
}