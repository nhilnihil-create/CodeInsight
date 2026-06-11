#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    double a,b,x;
    cin >> a >> b >> x;
    double ans;
    double pi=3.14159265258979;
    if(a*a*b/2.0<=x){
        ans=atan(2*(a*a*b-x)/(a*a*a));
        ans=(180*ans)/pi;
    }else {
        ans=pi/2-atan(2*x/(a*b*b));
        ans=(180*ans)/pi;
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}