#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

int n;

int findP(vt<int>& a) {
    vt<int> t(sz(a));
    iota(all(t), 1);

    int cnt = 0;
    for (; t != a; cnt++, next_permutation(all(t)));
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vt<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    cout << abs(findP(a) - findP(b));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
