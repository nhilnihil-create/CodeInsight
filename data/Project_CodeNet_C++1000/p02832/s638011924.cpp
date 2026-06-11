#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    int a[n+10];
    rep (i, n) cin >> a[i];

    bool one = false;
    rep (i, n) {
        if (a[i] == 1) {
            one = true;
            break;
        }
    }
    if (one == false) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 1;
    rep (i, n) {
        if (a[i] == cnt) {
            cnt++;
        }
    }
    cout << n - cnt + 1 << endl;

}
