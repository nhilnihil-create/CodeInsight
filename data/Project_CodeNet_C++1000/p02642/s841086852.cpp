#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> v(1000005, 0);

bool enum_divisors(long long N) {
    bool res = true;

    if (N != 1 && v[1] > 0) res = false;
    if (v[N] > 1) res = false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            if (v[i] > 0 || v[N / i] > 0) {
                res = false;
                break;
            }
        }
    }

    return res;
}

int main() {
    long long N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
        ++v[A[i]];
    }

    ll ans = 0;
    rep(i, N) if (enum_divisors(A[i]))++ ans;

    cout << ans << endl;
}
