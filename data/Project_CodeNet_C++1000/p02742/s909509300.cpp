#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (h % 2 == 0 || w % 2 == 0) {
        cout << h * w / 2 << endl;
    } else {
        cout << h * w / 2 + 1 << endl;
    }
    return 0;
}

