#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

const ll INF = 1e9;

int main(){
    int h,n; cin >> h >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,n) cin >> a[i] >> b[i];
    vector<ll> dp(h+10010,INF);
    dp[0] = 0;
    rep(i,n){
        rep(j,h+1){
            dp[j+a[i]] = min(dp[j+a[i]], dp[j]+b[i]);
        }
    }
    ll res = INF;
    for(int i=h;i<=h+10000;i++){
        res = min(res, dp[i]);
    }
    cout << res << endl;
}