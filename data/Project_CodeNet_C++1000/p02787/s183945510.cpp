#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = 1000001;
const double PI = acos(-1);

ll fexp(ll base, ll p){
    ll ans = 1;
    while (p){
        if (p&1){
            ans = (ans*base)%mod;
        }
        p = p >> 1;
        base = (base*base)%mod;
    }
    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    ll n, h, ans = oo;

    cin >> h >> n;
    vector<ll> dp(100100, oo);
    dp[0] = 0;

    for (int i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        for (int j=a; j<20200; j++){
            dp[j] = min(dp[j], dp[j-a] + b);
        }
    }

    for (int i=h; i<20200; i++){
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}