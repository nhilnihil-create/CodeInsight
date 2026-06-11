#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

ll dp[100100];
int main() {
    int n,m;
    cin >> n >> m;
    vector<int>a(m);
    rep(i,m) cin >> a[i];
    vector<bool> ok(100100,true);
    rep(i,m){
        ok[a[i]]=false;
    }
    dp[0]=1;
    for(int i = 0;i<=n;++i){
        if(ok[i+1]){
            dp[i+1]+=dp[i];
            dp[i+1]%=mod;
        }
        if(ok[i+2]){
            dp[i+2]+=dp[i];
            dp[i+2]%=mod;
        }
    }
    cout << dp[n] <<endl;
}