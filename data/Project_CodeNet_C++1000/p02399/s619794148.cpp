#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main(void){
    int a, b;
    cin >> a >> b;
    int d = a / b;
    int r = a % b;
    double f = (a * 1.0) / (b * 1.0);
    cout << setprecision(5);
    cout << d << " " << r << " " << fixed << f << endl;
}