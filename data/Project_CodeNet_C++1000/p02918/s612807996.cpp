#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int minus = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) minus++;
    }

    cout << n - 1 - max(0, minus - k * 2);
}
