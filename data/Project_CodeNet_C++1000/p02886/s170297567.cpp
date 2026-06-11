#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int d[n];
    rep (i, n) cin >> d[i];
    int res = 0;
    rep (i, n-1) {
        Rep(j, i+1, n) {
            res += d[i] * d[j]; 
        }
    }
    cout << res << endl;
}