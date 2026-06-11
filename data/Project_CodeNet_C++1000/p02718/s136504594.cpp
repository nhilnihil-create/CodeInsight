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

    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    sort(rall(a));
    if (a[m - 1] < (accumulate(all(a), 0) + 4 * m - 1) / (4 * m))
        cout << "No";
    else cout << "Yes";
}
