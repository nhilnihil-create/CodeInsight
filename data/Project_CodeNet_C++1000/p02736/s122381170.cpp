#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;

vector<ll> fac;
bool CombParity(int a, int b) {
    if (fac[a] - fac[a-b] - fac[b] > 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n; cin >> n;
    string a; cin >> a;
    vector<int> b(n);
    rep(i, n) {
        b[i] = a[i] - '1';
    }

    fac.assign(n+1, 0);
    int i = 2;
    while (i <= n) {
        int j = 1;
        while (i * j <= n) {
            fac[i*j]++;
            j++;
        }
        i *= 2;
    }
    rep(i, n) {
        fac[i+1] += fac[i];
    }

    bool parity = 0;
    rep(i, n) {
        parity ^= (b[i]%2) * CombParity(n-1, i);
    }

    if (parity == 1) {
        cout << 1 << endl;
        return 0;
    }

    bool flag1 = 0;
    rep(i, n) {
        if (b[i] == 1) flag1 = 1;
    }
    if (flag1) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, n) {
        if (b[i] == 2) b[i] = 1;
    }
    parity = 0;
    rep(i, n) {
        parity ^= b[i] * CombParity(n-1, i);
    }
    if (parity) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }



    return 0;
}