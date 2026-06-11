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
    ll m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if (m1 != m2) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

