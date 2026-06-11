#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    double x1, x2, y1, y2, dis;
    cin >> x1 >>y1 >> x2 >> y2;
    dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    cout << fixed;
    cout << setprecision(5) << dis << endl;
}

