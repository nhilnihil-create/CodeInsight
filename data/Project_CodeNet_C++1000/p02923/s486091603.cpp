#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

ll N;
vector<ll> H;
vector<ll> dp;

int main() {
    cin >> N;
    H.resize(N);
    dp.resize(N);

    REP(i, N) {
        cin >> H[i];
    }

    dp[0] = 0;
    for(ll i = 1; i < N; ++i) {
        if(H[i - 1] >= H[i]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 0;
        }
    }

    ll ans = 0;
    REP(i, N) {
        if(dp[i] > ans) {
            ans = dp[i];
        }
    }
    cout << ans << endl;

    return 0;
}