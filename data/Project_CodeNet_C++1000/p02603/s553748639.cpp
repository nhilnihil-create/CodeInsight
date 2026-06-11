#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
ll a[100];
ll n;
ll dp[100];
int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    cin >> n;

    FOR(i,1,n) cin >> a[i];

    // pair<int, int> dp[100][2];
    // dp[0][0] = {1000, 0};
    // dp[0][1] = {1000, 0};

    // FOR(i,1,n){
    //     dp[i][0] = dp[i-1][0].first > dp[i-1][1].first + dp[i-1][1].second * a[i] ? dp[i-1][0]: make_pair(dp[i-1][1].first + dp[i-1][1].second * a[i], 0);
    //     dp[i][1] = dp[i-1][1].second > dp[i-1][0].first / a[i]? dp[i-1][1] : make_pair(dp[i-1][0].first - (dp[i-1][0].first/a[i]) *a[i], dp[i-1][0].first/a[i]);
    // }

    // cout << dp[n][0].first << endl;

    dp[0] = 1000;
    FOR(i,1,n) {
        chmax(dp[i], dp[i-1]);
        FOR(j, 0, i-2) {
            ll cnt = dp[j] / a[j+1];
            chmax(dp[i], dp[j] - cnt * a[j+1] + cnt * a[i]);
        }
    } 

    cout << dp[n] << endl;
    return 0;
}
