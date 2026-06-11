#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return 1;} return 0;}
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll, ll>;
int main() {
    int N; cin >> N;
    vector<pll> A(N);
    rep(i, N) {cin >> A[i].first, A[i].second = i;}
    sort(A.begin(), A.end(), greater<pll>());

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    rep(i, N){
        rep(j, N-i){
            chmax(dp[i+1][j], dp[i][j] + A[i+j].first * (A[i+j].second - i));
            chmax(dp[i][j+1], dp[i][j] + A[i+j].first * ((N-1-j) - A[i+j].second));
        }
    }
    ll res = 0;
    rep(i, N+1) chmax(res, dp[i][N-i]);
    cout << res << endl;
    return 0;
}