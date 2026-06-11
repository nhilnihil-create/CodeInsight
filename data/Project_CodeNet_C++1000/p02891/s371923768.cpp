#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s, s2;
    ll k;
    cin >> s >> k;
    int n = s.size();
    s2 = s + s;

    if (n == 1) {
        cout << k / 2 << endl;
        return 0;
    } else if (all_of(s.begin(), s.end(), [s](char x) { return x == s[0]; })) {
        cout << n * k / 2 << endl;
        return 0;
    }

    int cnt = 1;
    ll ans = 0, ans2 = 0;
    rep(i, n) {
        if (s[i] == s[i + 1])
            cnt++;
        else
            ans += cnt / 2, cnt = 1;
    }

    cnt = 1;
    rep(i, n * 2) {
        if (s2[i] == s2[i + 1])
            cnt++;
        else
            ans2 += cnt / 2, cnt = 1;
    }

    ans = ans * k + (ans2 - ans * 2) * (k - 1);
    cout << ans << endl;
    return 0;
}
