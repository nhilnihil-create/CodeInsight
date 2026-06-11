#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string l;
    cin >> l;
    vector<vector<ll>> dp(l.size()+1, vector<ll>(2, 0));
    dp[0][1] = 1;
    rep(i, l.size()){
        dp[i+1][0] += dp[i][0] * 3;
        if(l[i] == '0'){
            dp[i+1][1] += dp[i][1];
        }else{
            dp[i+1][0] += dp[i][1];
            dp[i+1][1] += (dp[i][1] * 2);
        }
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    cout << (dp[l.size()][0] + dp[l.size()][1]) % mod << endl;
}