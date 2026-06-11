#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, k, ans = 0;
    cin >> a >> b >> c >> k;
    
    if (k > a) {
        k -= a;
        ans += a;
    } else {
        cout << k << endl;
        return 0;
    }

    if (k <= b) {
        cout << ans << endl;
    } else {
        k -= b;
        cout << ans - k << endl;
    }
    return 0;
}