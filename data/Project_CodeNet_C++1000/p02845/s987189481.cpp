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
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 1;
    int z = 3;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            ans = ans * z % mod;
            z--;
        } else {
            ans = ans * cnt[a[i]-1] % mod;
            cnt[a[i]-1]--;
        }
        cnt[a[i]]++;
    }
    cout << ans << "\n";





    return 0;
    
}