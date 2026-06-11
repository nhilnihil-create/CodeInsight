#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector

int main(){
    int n,t;
    cin >> n >> t;
    ve<P> ab;
    rep(i,n){
        ll a,b;
        cin >> a >>b;
        ab.push_back(P(a,b));
    }

    sort(ab.begin(), ab.end());

    ve<ve<ll>> dp1(n+1,ve<ll>(t+1));
    rep(i,n){
        ll a = ab[i].first, b = ab[i].second;
        rep(j,min(a, (ll)t)) dp1[i+1][j] = dp1[i][j];
        rep(j,t-a+1){
            dp1[i+1][j+a] = max(dp1[i][j+a], dp1[i][j]+b);
        }
    }

    ll ans=0;
    rep(i,n){
        ll memo = ab[i].second;
        ans = max(ans, memo+dp1[i][t-1]);
    }

    cout << ans << endl;
    return 0;
}