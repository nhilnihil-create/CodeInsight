#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//ABC 129 c.cpp
int main() {
    ll mod = 1000000007;
    int n,m;
    cin >> n >> m;

    vector<ll> dp(n+1);
    dp[0] = dp[1] = 1;
    vector<int> a(m);
    rep(i,m){
        cin >> a[i];
        dp[a[i]] = -1;
    }

    ll ans = 0;
    for(int i = 2;i < n+1;i++){
        if(dp[i] != -1){
            dp[i] = (dp[i-1] != -1)*dp[i-1] + (dp[i-2] != -1)*dp[i-2];
            dp[i] %= mod;
        }
    }
    ans = dp[n]%mod;
    cout <<ans<<endl;
}