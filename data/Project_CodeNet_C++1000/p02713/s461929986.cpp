#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

int main(){
    ll k;
    cin >> k;
    ll ans = 0;
    rep(a, 1, k+1){
        rep(b, 1, k+1){
            rep(c, 1, k+1){
                ll g = gcd(a, b);
                ans += gcd(g, c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}