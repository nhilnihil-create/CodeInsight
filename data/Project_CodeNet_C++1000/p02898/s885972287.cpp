#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int h, res = 0;
    rep (i, n) {
        cin >> h;
        if (h >= k) res++;
    }
    cout << res << endl;
}