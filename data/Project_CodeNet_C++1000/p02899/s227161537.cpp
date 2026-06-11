#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }
    vector<ll> b(n);
    rep(i, n) { b[a[i] - 1] = i + 1; }
    rep(i, n) {
        if (i != n - 1)
            cout << b[i] << " ";
        else
            cout << b[i] << endl;
    }
    return 0;
}