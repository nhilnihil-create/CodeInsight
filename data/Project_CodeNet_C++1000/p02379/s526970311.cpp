#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double result;
    result = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    
    cout.precision(5);
    cout << fixed << result << endl;
    
    return 0;
}