#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a%b==0) return b;
    else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll N, M;
    cin >> N >> M;

    ll a[N];
    rep(i, N) {
        cin >> a[i];
        a[i] = a[i] / 2;
    }

    bool ok = true;
    ll ai, k1 = 0, k2;
    rep(i, N) {
        ai = a[i];
        if (i==0) {
            while (ai %2 == 0) {
                ai /= 2;
                k1++;
            }
        } else {
            k2 = 0;
            while (ai %2 == 0) {
                ai /= 2;
                k2++;
            }
            if (k1 != k2) {
                ok = false;
                break;
            }
        }
    }

    ll x = 1;
    rep(i, N) x = lcm(x, a[i]);

    if (ok) cout << (M / x + 1) / 2 << endl;
    else cout << 0 << endl;

    return 0;
}

