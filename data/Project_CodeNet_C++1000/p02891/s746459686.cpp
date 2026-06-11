#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    string t = s + s;
    int sum = 0, sum2 = 0;
    rep(i, 1, 2 * n) {
        if (t[i - 1] == t[i]) {
            sum++;
            t[i] = '1';
        }
    }
    // cout << t << "\n";
    // cout << t[2 * n - 1] << t[0] << "\n";
    if (t[2 * n - 1] == t[0]) {
        sum2++;
        t[2 * n - 1] = '1';
    }
    int cnt = 0, cnt2 = 0;
    rep(i, 1, n) {
        if (s[i - 1] == s[i]) {
            cnt++;
            s[i] = '1';
        }
    }
    int ans = 0;
    // cout << sum << " " << sum2 << "\n";
    if (k == 1) {
        ans = cnt;
    } else {
        if (k % 2 == 0) {
            ans = sum * (k / 2) + sum2 * (k / 2 - 1);
        } else {
            ans = sum * (k / 2) + cnt;
        }
    }
    // cout << t[2 * n - 1] << t[0] << "\n";
    cout << ans << "\n";
}