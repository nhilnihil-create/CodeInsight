#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using P = pair<int, int>;

#define LARGE 1000000007

int main() {
    ll n;
    cin >> n;
    ll k[61];
    rep (i, 61) k[i] = 0;
    rep (i, n) {
        ll a;
        cin >> a;
        rep (j, 61) if ((a>>j)&1) k[j]++;
    }

    ll sum = 0;
    rep (i, 61) {
        ll dat = k[i] * (n-k[i]);
        rep (j, i) dat = dat * 2 % LARGE;
        sum += dat;
        sum %= LARGE;
    }

    cout << sum << endl;
	return 0;
}
