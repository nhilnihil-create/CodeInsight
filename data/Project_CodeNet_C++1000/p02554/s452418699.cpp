#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)n; ++i)

typedef long long ll;

const ll MOD = 1e9 + 7;

using namespace std;

ll powmod(ll a, ll b) {
    ll val = 1;
    REP(_, b) {
        val *= a;
        val %= MOD;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;

    ll cnt = powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N);
    cnt %= MOD;
    cnt = (cnt + MOD) % MOD;

    cout << cnt << endl;
}