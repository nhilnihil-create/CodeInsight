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
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int in=n-1;in>=0;--in) {
        for(int jn=n-1;jn>in;--jn) {
            if(s[in]==s[jn]) chmax(dp[in][jn], dp[in+1][jn+1]+1);
            chmax(ans, min(dp[in][jn], jn-in));
        }
    }
    cout << ans << endl;
    return 0;
}
