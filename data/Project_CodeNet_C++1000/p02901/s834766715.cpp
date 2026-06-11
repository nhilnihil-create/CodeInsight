#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)

int main(){
    int n,m; cin>>n>>m;
    vector<P> key;
    rep(i,m){
        int a,b; cin>>a>>b;
        int bit = 0;
        rep(j,b){
            int c; cin>>c; c--;
            bit |= 1<<c;
        }
        key.emplace_back(bit,a);
    }

    vector<int> dp(1<<n,1e9);
    dp[0] = 0;
    rep(bit,1<<n){
        rep(i,m){
            int t = bit | key[i].first;
            chmin(dp[t], dp[bit]+key[i].second);
        }
    }
    int ans = dp.back();
    if(ans==1e9) ans=-1;
    cout << ans << endl;
    return 0;
}