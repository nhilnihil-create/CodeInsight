#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

int main() {
    ll A, B, M, ans = 0;
    cin >> A >> B >> M;
    vi a(A), b(B);
    ll minA = INF, minB = INF;
    for (ll i = 0; i < A; i++) {
        cin >> a[i];
        minA = min(minA, a[i]);
    }
    for (ll i = 0; i < B; i++) {
        cin >> b[i];
        minB = min(minB, b[i]);
    }

    ans = minA + minB;

    for (ll i = 0; i < M; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        ans = min(ans, a[x - 1] + b[y - 1] - c);
    }

    cout << ans << endl;
}
