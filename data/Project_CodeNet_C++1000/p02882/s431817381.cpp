#include <iostream>
#include <cmath>
using namespace std;
double const PI = acos(-1);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a,b,x;
    cin >> a >> b >> x;
    double s = x/a;
    double h;
    double rad;
    if(2*s >= a*b){
        h = 2*(a*b - s)/a;
        rad = atan2(h,a);
    } else{
        h = 2*s/b;
        rad = atan2(b,h);
    }
    double deg = rad*180/PI;
    printf("%.10f\n",deg);
    return 0;
}
//Saw the editorial