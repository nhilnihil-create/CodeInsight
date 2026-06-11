#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> ans(n, 1);
    rep(i, n) {
        if (s.substr(i, 2) == "RR") {
            ans[i + 2] += ans[i];
            ans[i] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L' && s[i - 1] == 'L') {
            ans[i - 2] += ans[i];
            ans[i] = 0;
        }
    }

    rep(i, n - 1) cout << ans[i] << ' ';
    cout << ans[n - 1] << endl;

    return 0;
}
