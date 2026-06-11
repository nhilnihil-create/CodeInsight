#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;

    if (abs(a - b) <= (v - w) * t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
