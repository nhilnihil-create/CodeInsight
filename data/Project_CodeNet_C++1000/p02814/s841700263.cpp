#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

ll gcd_func(ll a, ll b) {
    if (a < b) return gcd_func(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

ll lcm_func(ll a, ll b) {
    return a / gcd_func(a, b) * b;
}

int main() {
    ll N, M, ans = 0;
    cin >> N >> M;
    vi A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll a = 0, c = 1;
    while (A[0] % 2 == 0) {
        A[0] /= 2;
        a++;
        c *= 2;
    }
    for (ll i = 1; i < N; i++) {
        ll b = 0;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            b++;
        }
        if (a != b) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll l = 1;
    for (ll i = 0; i < N; i++) {
        l = lcm_func(l, A[i]);
    }

    ans = ceil(double(floor(M / (l*c/2))) / 2);
    cout << ans << endl;
}
