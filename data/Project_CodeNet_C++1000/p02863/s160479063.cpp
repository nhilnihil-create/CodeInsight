#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, t;
    cin >> n >> t;

    vector<pint> ab(n+1);
    for(int in=1;in<=n;++in) {
        cin >> ab[in].first >> ab[in].second;
    }
    sort(ab.begin(), ab.end());

    vector<vector<int>> dp(3501, vector<int>(3501, 0));
    for(int in=0;in<n;++in) {
        for(int it=0;it<=t;++it) {
            dp[in+1][it] = dp[in][it];
            if(it-ab[in+1].first>=0) {
                dp[in+1][it] = max(dp[in][it], dp[in][it-ab[in+1].first]+ab[in+1].second);
            }
        }
    }

    int ans = 0;
    for(int in=1;in<=n;++in) {
        chmax(ans, dp[in-1][t-1]+ab[in].second);
    }

    cout << ans << endl;
    return 0;
}
