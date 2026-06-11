#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
const int MOD = 1e9+7;

ll power(ll a, ll b){
    ll r=1;
    while(b>0){
        if(b&1)
            r=r*a %MOD;
        a = a*a %MOD;
        b/=2;
    }
    return r;
}

int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = 1.0*w*h/2;
    cout << ans << " ";
    if(x == 1.0*w/2 && y == 1.0*h/2)
        cout << 1;
    else
        cout << 0;
}
