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
    ll n;
    cin >> n;
    rep(i, 50000) {
        double temp = i * 1.08;
        if ((ll)temp == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}

