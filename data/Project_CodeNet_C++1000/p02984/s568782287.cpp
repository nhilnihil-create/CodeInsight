#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll x = 0;
    rep(i, N) { x = x + pow(-1, i) * a[i]; }
    cout << x << " ";
    rep(i, N - 1) {
        cout << 2 * a[i] - x << " ";
        x = 2 * a[i] - x;
    }
    cout << endl;
    return 0;
}
