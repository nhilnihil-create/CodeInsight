#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int mi = min(p[i - 1], min(p[i], p[i + 1]));
        int ma = max(p[i - 1], max(p[i], p[i + 1]));

        if (p[i] != mi && p[i] != ma) ans++;
    }

    cout << ans << endl;
}
