/**
*    created: 27.06.2020 00:54:58
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> s(n+1);
    rep(i,m) {
        int a;
        cin >> a;
        s[a] = -1;
    }
    //-1のところには遷移しないようにdp
    vector<int> dp(n+1);
    dp[0] = 1;
    rep(i,n) rep2(t,i+1,min(n,i+2)+1) if (s[t] == 0) {
        dp[t] += dp[i];
        dp[t] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}