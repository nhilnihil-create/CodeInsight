#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<ll> dp(n+1,1);
    rep(i,m){
        dp[a[i]]=0;
    }
    for(int i=1; i<n; ++i){
        if(dp[i+1]==0) continue;
        dp[i+1]=dp[i]+dp[i-1];
        dp[i+1]=dp[i+1]%1000000007;
    }
    cout << dp[n] << "\n";
    return 0;
}   