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
    int a;
    cin >> a;
    a /= 2;
    int x = ord(a, 2);
    rep(i, N - 1) {
        int b;
        cin >> b;
        b /= 2;
        if (ord(b, 2) != x) {
            cout << 0 << endl;
            return 0;
        }
        a = lcm(a, b);
        if (a > M) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 0;
    for (int i = 1; a * i <= M; i += 2) {
        ans++;
    }
    cout << ans << endl;
}
