#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;

    bool ok = true;
    int cnt[n];
    for (int i = 0; i < n; i++) cnt[i] = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (i == 0 && d != 0) ok = false;
        cnt[d]++;
        m = max(m, d);
    }

    if (cnt[0] != 1) ok = false;
    
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            ans = ans * cnt[i - 1] % mod;
        }
    }

    cout << ans << endl;
    return 0;
}