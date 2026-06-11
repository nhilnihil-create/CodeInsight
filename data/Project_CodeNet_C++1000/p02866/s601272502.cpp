#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const lint MOD = 998244353;

int main() {
    lint n;
    cin >> n;

    vector<lint> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    if (d[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    map<lint, lint> mp;
    for (auto x:d) mp[x]++;

    lint ans = 1;
    for (int i = 1; i < n; i++) {
        ans *= mp[d[i] - 1];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
