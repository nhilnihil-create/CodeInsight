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

    ll minX = 1;
    rep(i, N) {
        if (minX > M) break;
        minX = lcm(minX, a[i]);
    }

    rep(i, N) {
        ll minX2 = minX;
        while ((a[i] > 0 && minX2 > 0) && (minX2 % 2 == 0 || a[i] % 2 == 0)) {
            if (minX2 % 2 == 1 || a[i] % 2 == 1) M = 0;
            minX2 /= 2;
            a[i] /= 2;
        }
    }

    // cout << minX << endl;
    cout << M / minX - M / (2 * minX) << endl;

    return 0;
}

