#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    double a,b,x;
    cin >> a >> b >> x;
    double v = a*a*b;
    double rad;
    if(2*x < v){
        rad = atan(a*b*b/2/x);
    }else if(2*x == v){
        rad = M_PI / 4;
    }else{
        rad = atan(2*(v-x)/a/a/a);
    }
    double ans = rad/2/M_PI*360;
    cout << fixed << setprecision(10) << ans; 
}