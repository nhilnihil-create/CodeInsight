#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    int cnt[n + 1] = {};
    k = min(k, 50);
    while (k--) {
        rep(i, 0, n) {
            int s = max(0, i - a[i]);
            int e = min(n - 1, i + a[i]);
            cnt[s]++;
            cnt[e + 1]--;
        }
        rep(i, 0, n - 1) cnt[i + 1] += cnt[i];
        rep(i, 0, n) a[i] = cnt[i];
        rep(i, 0, n + 1) cnt[i] = 0;
    }
    rep(i, 0, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}
