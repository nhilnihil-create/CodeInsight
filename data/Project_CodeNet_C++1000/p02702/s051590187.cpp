#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long
const int MOD = 1000000007;

signed main() {
    string s;
    cin >> s;
    vector<int> res(2019, 0);
    int ex;
    int k = 0;
    res[k]++;
    int ten = 1;
    int n = s.size();
    rep(i, n) {
        ex = s[n - 1 - i] - '0';
        k = (k + ex * ten) % 2019;
        ten = (ten * 10) % 2019;
        // cout << k << endl;
        res[k]++;
    }
    int ans = 0;
    for (auto i : res) {
        ans += i * (i - 1) / 2;
    }
    printf("%lld", ans);
}