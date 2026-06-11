#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
ll c[2010][2010];
void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int s;
    cin >> s;
    init(2005);
    ll ans = 0;
    for (int i = 1; i * 2 <= s - 1; i++) {
        ans = (ans + c[s - 2 * i - 1][i - 1]) % mod;
    }
    cout << ans << endl;
    return 0;
}
