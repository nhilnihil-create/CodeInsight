#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(k, 1000) {
        ll d[3] = {k / 100, k / 10 % 10, k % 10};
        int idx = 0;
        rep(i, s.size()) {
            if (s[i] - '0' == d[idx])
                idx++;

            if (idx == 3) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}