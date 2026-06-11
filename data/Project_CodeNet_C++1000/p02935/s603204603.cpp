#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    double v[n];
    rep (i, n) cin >> v[i];
    sort(v, v + n);
    rep (i, n) {
        if (i == 0 || i == 1) v[i] /= pow(2, n-1); 
        else v[i] /= pow(2, n-i);
    }
    double res = 0;
    rep (i, n) res += v[i];
    cout << res << endl;
}