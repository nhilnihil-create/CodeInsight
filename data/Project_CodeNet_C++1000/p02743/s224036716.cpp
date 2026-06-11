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
    ll a, b, c;
    cin >> a >> b >> c;
    ll left = 4 * a * b, right = (c - a - b) * (c - a - b);
    if (left < right && c - a - b > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

