#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int MN = 2e5 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
int N, a[MN], pre[MN], suf[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(pre, -0x3f, sizeof(pre));
    memset(suf, -0x3f, sizeof(suf));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i]);
    }
    for (int i = N; i >= 1; i--) suf[i] = max(suf[i + 1], a[i]);
    for (int i = 1; i <= N; i++) {
        cout << max(pre[i - 1], suf[i + 1]) << '\n';
    }
    return 0;
}
