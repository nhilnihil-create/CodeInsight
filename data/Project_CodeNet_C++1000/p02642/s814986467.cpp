#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b) {
    if (a < b) a = b;
}
template <class T1, class T2>
inline void chmin(T1 &a, const T2 &b) {
    if (a > b) a = b;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    sort(all(A));
    ll M = A[N - 1] + 1;
    vector<bool> table(M, false);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (table[A[i]] == false) {
            for (int j = A[i]; j < M; j += A[i]) {
                table[j] = true;
            }
            if (i < N - 1) {
                if (A[i + 1] == A[i]) {
                    continue;
                }
            }
            ++ans;
        }
    }

    cout << ans << endl;
}