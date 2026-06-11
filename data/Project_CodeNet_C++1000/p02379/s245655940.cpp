#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double ans = sqrt( pow(x2 - x1, 2) + pow(y1 - y2, 2) );
    cout << setprecision(10) << ans << endl;
    
}

