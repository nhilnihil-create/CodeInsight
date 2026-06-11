#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 3e5+9;
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    ll ans = 0;
    const ll INF = 1e18;
    vector<vector<ll>> f(n+2, vector<ll>(n+2, -INF));
    f[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        int ind = a[i-1].second+1;
        ll val = a[i-1].first;
        for(int j = 0; j <= i; j++) {
            // r, l
            f[i][j] = f[i-1][j]+abs(n-(i-j)+1-ind) * val;
            if(j > 0) {
                f[i][j] = max(f[i][j], f[i-1][j-1]+abs(ind-j)*val);
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;



    return 0;
    
}
