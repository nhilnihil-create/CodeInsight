#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll ord(ll N, ll p) {
    ll res = 0;
    while (N % p == 0) {
        res++;
        N /= p;
    }
    return res;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i, N) cin >> a[i], a[i] /= 2;
    ll x = ord(a[0], 2);
    rep(i, N) {
        if (x != ord(a[i], 2)) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll l = a[0];
    rep(i,N) {
        l = lcm(l, a[i]);
        if (l > M) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 0;
    for (int i = 1; l * i <= M; i+=2) {
        ans++;
    }
    cout << ans << endl;
}