#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    ll L = 1;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] /= 2;
        L = lcm(L, a[i]);
        if (L > M) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if ((L / a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (M / L + 1) / 2 << endl;
}