#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    const ll MOD = 1000000007;
    ll N, K; cin >> N >> K;
    vl A(N); rep(i, N) cin >> A[i];

    ll res = 0;
    rep(i, N) {
        ll cnt1 = 0;
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) cnt1++;
        }

        ll cnt2 = 0;
        rep(j, N) {
            if (A[i] > A[j]) cnt2++;
        }

        res += (cnt1 * K) % MOD;
        res %= MOD;

        res += K * (K - 1) / 2 % MOD * cnt2 % MOD;
        res %= MOD;
    }

    cout << res << endl;
}
