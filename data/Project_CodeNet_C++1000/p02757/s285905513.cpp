#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    reverse(all(s));

    vec d(n+1);

    lint res = 0;

    lint cur = 1;
    for (int i = 1; i <= n; i++) {
        int nd = s[i-1] - '0';
        d[i] = (d[i-1] + cur * nd) % p;
        cur *= 10;
        cur %= p;
    }

    if (p == 2 || p == 5) {
        rep(i, n) {
            int nd = s[i] - '0';
            if (nd % p == 0) {
                res += (n - i);
            }
        }
    }
    else {
        map<int, int> mp;
        rep(i, n+1) mp[d[i]]++;
        for (auto&& ps : mp) {
            lint v = ps.second;
            res += v * (v-1) / 2;
        }
    }

    cout << res << endl;
    return 0;
}
