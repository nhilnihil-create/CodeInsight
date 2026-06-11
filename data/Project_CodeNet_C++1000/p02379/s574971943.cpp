#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(8) << pow(pow(abs(x1-x2),2)+pow(abs(y1-y2),2),0.5) << endl;
    return 0;
}
