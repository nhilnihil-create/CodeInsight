#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

void solve(void)
{
    int n;
    cin >> n;
    vector<int> b(n - 1);
    rep(i, n - 1) cin >> b[i];
    vector<int> a(n);
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1; ++i)
        a[i] = min(b[i - 1], b[i]);
    int ans = accumulate(a.begin(), a.end(), 0);
    cout << ans << endl;
}
int main(void) { solve(); }
