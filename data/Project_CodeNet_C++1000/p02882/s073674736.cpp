#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    double a,b,x;
    cin >> a >> b >> x;
    x = x / a;
    if(a*b/2 >= x){
        double c = (2*x)/b;
        cout << std::fixed << std::setprecision(15) << 90 - atan(c/b)/ M_PI * 180.0 << endl;        
    }else{
        double c = (2*(a*b -x))/a;
        cout << std::fixed << std::setprecision(15) <<  atan(c/a)/ M_PI * 180.0 << endl;
    }
}
