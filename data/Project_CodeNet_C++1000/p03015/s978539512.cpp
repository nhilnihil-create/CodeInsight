#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <class T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

string L;
vector<vector<int>> dp;
int rec(int d, bool istight) {
    if (d == 0)
        return dp[d][istight] = istight;
    bool n = L[d - 1] - '0';
    if (istight) {
        ll tmp = (~dp[d - 1][1] ? dp[d - 1][1] : rec(d - 1, true));
        return dp[d][1] = tmp * (n + 1) % MOD;
    } else {
        ll tmp1 = (~dp[d - 1][0] ? dp[d - 1][0] : rec(d - 1, false));
        ll tmp2 = (~dp[d - 1][1] ? dp[d - 1][1] : rec(d - 1, true));
        return dp[d][0] = (tmp1 * 3 + tmp2 * n) % MOD;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> L;
    int len = L.length();

    dp.resize(len + 2, vector<int>(2, -1));
    dp[0][1] = 1;

    cout << (rec(len, true) + rec(len, false)) % MOD << endl;
    return 0;
}
