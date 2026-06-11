#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    a.push_back(a[0] + k);
    int l = 0;
    rep(i, n) { l = max(l, a[i + 1] - a[i]); }
    int ans = k - l;
    cout << ans << endl;
    return 0;
}