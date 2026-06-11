#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = c-a-b;
    if (d*d <= 4*a*b || d < 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}