#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main(void){
    double r;
    cin >> r;
    double s = r * r * 1.0 * 3.141592653589;
    double l = r * 2.0 * 3.141592653589;
    cout << setprecision(6);
    cout << fixed << s << " " << l << endl;
}