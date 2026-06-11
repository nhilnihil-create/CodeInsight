/*input
5
2 1 5 4 3
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    ll ans = 0;
    int ma = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a < ma) ans += ma-a;
        else ma = a;
    }
    cout << ans << endl;
}