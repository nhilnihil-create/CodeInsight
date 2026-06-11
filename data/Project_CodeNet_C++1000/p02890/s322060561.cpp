#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n), d(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        c[a]++;
    }
    for (int i = 0; i < n; i++) {
        d[c[i]]++;
    }
    vector<int> s(n + 1), f(n + 1);
    for (int i = 0; i <= n; i++) {
        s[i] = d[i] + (i != 0 ? s[i - 1] : 0);
    }
    ll y = 0;
    for (int i = 1; i <= n; i++) {
        y += i * d[i];
        f[i] = y + (s[n] - s[i]) * i;
        f[i] /= i;
    }
    f[0] = 1e9;
    vector<int> ans(n + 1);
    int id = 1;
    for (int i = n; i >= 0; i--) {
        for (; id <= n && id <= f[i]; id++) {
            ans[id] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}