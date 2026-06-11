#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double x1,x2,y1,y2,p1p2;
    cin >> x1 >> x2 >> y1 >> y2;
    p1p2 = sqrt(pow((y1-x1), 2) + pow((y2-x2), 2));
    
    cout << fixed << setprecision(15) << p1p2 << "\n";
    
    return 0;
}
