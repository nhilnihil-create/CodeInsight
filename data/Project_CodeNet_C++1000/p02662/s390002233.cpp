#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n,s;
    cin >> n >> s;
    vector<ll> dp(s+1),p(s+1);
    ll ans = 0;
    vector<int> a(n);
    ll mod = 998244353;
    rep(i,n){
        cin >>a[i];
        
    }
    dp[0] = 1;
    rep(i,n){
        
        p = dp;
        int ai = a[i];
        
        rep(j,s+1){
            dp[j] = p[j]*2;
            if(j>=ai) dp[j] += p[j-ai]; 
            dp[j] %= mod;
        }
    }
    ans = dp[s]%mod;
    cout << ans << endl;
}
