#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
//const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    int n, t; cin >> n >> t;
    vector<P> ar(n);
    rep(i,n) cin >> ar[i].first >> ar[i].second;
    sort(ar.begin(), ar.end());
    vector<vector<int>> dp(n,vector<int>(t));
    rep(i,n) dp[i][0] = 0;
    rep(i,t){
        if (i >= ar[0].first){
            dp[0][i] = ar[0].second;
        }
    }
    repp(i,n,1){
        repp(j,t,1){
            int c = 0;
            if (j >= ar[i].first){
                c = dp[i-1][j-ar[i].first] + ar[i].second;
            }
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],c});
        }
    }
    int ans = 0;
    repp(i,n,1) ans = max(ans, ar[i].second + dp[i-1][t-1]);
    cout << ans << endl;
}