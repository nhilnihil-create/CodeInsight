#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    int a,b,h,m;
    double s,t,pi=3.14159265358979;
    cin >> a >> b >> h >> m;
    if(m%2) s = (30*h+(m-1)/2)%360+0.5;
    else s = (30*h+m/2)%360;
    t = (6*m)%360;
    cout <<fixed << setprecision(9) << sqrt(a*a+b*b-2*a*b*cos(pi*(s-t)/180)) << endl;
}
