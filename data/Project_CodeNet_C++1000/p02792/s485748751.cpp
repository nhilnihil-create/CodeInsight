#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int cnt[10][10];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        cnt[s[0] - '0'][s[s.size() - 1] - '0']++;
    }

    ll ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }

    cout << ans << endl;
    return 0;
}
