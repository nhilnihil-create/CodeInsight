#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i, --i;
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) (s[i] += s[i - 1] + a[i - 1]) %= k;
    map<int, int> m;
    ll r = 0;
    for (int i = 1; i < min(k, n + 1); ++i) ++m[s[i]];
    for (int i = 0; i <= n; ++i) {
        r += m[s[i]];
        if (i + k <= n) ++m[s[i + k]];
        if (i + 1 <= n) --m[s[i + 1]];
    }
    cout << r << endl;
    for (int i : s) cerr << i << " ";
    cerr << endl;
}