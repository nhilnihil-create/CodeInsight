#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());
    for (int i = d[d.size() / 2];; --i) {
        if (i == d[d.size() / 2 - 1])
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}