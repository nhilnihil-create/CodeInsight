#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double a=0, b=0, x=0, ans=0, l=0;
    cin >> a >> b >> x;
    if((int)x > (int)(a*a*b / 2)){
        l = 2*x / (a*a) - b;
        ans = atan2(b-l, a);
    }
    else{
        l = 2*x / (a*b);
        ans = atan2(b, l);
    }
    cout << fixed << setprecision(10) << ans * 180 / 3.14159265358979323846;
    return 0;
}