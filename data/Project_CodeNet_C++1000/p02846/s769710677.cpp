#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e9+9;
 
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
 
const int N = 2e5+9;
int a[N], cnt[N];
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll t1, t2; cin >> t1 >> t2;
    ll a1, a2; cin >> a1 >> a2;
    ll b1, b2; cin >> b1 >> b2;
    ll p = (a1-b1) * t1, q = (a2-b2) * t2;
    // ll p, q; cin >> p >> q;
    if(p + q == 0) {
        cout << "infinity" << endl;
        return 0;
    } 
    if(p < 0) {p *= -1; q *= -1;}
    if(p + q > 0) {
        cout << "0\n";
        return 0;
    }
    // p > 0 && q < 0
    ll r = -p-q;
    ll ans = 2*(p / r + 1) - (p%r==0) - 1;
    cout << ans << "\n";





    return 0;
    
}