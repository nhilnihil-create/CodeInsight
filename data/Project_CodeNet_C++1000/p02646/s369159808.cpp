#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    long double dist = abs(b - a);
    if (dist / t + w <= v) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}