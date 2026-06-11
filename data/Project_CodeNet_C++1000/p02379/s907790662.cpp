#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    // Here your code !
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed
         << setprecision(5)
         << sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}