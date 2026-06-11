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

    ve<ve<ll>> dp1(n+1,ve<ll>(t+1)), dp2(n+1,ve<ll>(t+1));
    rep(i,n){
        ll a = ab[i].first, b = ab[i].second;
        rep(j,min(a,(ll)t)){
            dp1[i+1][j] = dp1[i][j];
        }
        rep(j,t-a+1){
            dp1[i+1][j+a] = max(dp1[i][j+a], dp1[i][j]+b);
        }
        ll a2 = ab[n-1-i].first, b2 = ab[n-1-i].second;
        rep(j,min(a2, (ll)t)){
            dp2[n-i-1][j] = dp2[n-i][j];
        }
        rep(j,t-a2+1){
            dp2[n-i-1][j+a2] = max(dp2[n-i][j+a2],dp2[n-i][j]+b2);
        }
    }

    ll ans=0;
    rep(i,n){
        ll memo = ab[i].second;
        ll memo1=0;
        rep(j,t){
            memo1 = max(memo1, dp1[i][j] + dp2[i+1][t-1-j]);
        }
        ans = max(ans, memo+memo1);
    }

    cout << ans << endl;
    return 0;
}
