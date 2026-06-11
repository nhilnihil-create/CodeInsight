#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;
int X;

void solve() {
    vector<bool> dp(100001,false);
    REP(i,6) dp[100 + i] = true;
    FOR(i,106,100001) {
        dp[i] = dp[i-100] || dp[i-101] || dp[i-102] || dp[i-103] || dp[i-104] || dp[i-105];
    };
    cin >> X;

    auto ans = dp[X] ? "1" : "0";
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}