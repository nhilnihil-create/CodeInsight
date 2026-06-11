#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define pi 3.141592653589793
int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    double ans;
    if (a*a*b <= 2*x) {
        ans = atan2((double)2*b - 2*x/(double)(a*a), a)*180/pi;
    }else{
        //cout << (double)b << ',' << (double)2*x/(double)(a*b) << endl;
        ans = atan2((double)b, (double)2*x/(double)(a*b))*180/pi;
    }
    cout << setprecision(15) << ans << endl;
    return 0;
}
