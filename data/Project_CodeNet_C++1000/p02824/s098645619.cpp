#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

bool isOK(ll N, ll M, ll V, ll P, vector<ll>& A, ll x) {
    if (x < P) return true;
    ll now = A[x] + M;

    if (A[P - 1] > now) return false;

    ll score = 0;
    score += (P - 1) * M;
    score += (N - x) * M;

    reps(i, P - 1, x) { score += min(M, max(0LL, now - A[i])); }
    return score >= M * V;
}

int main() {
    INIT;

    ll N, M, V, P;
    cin >> N >> M >> V >> P;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(ALL(A), greater<ll>());

    ll ok = -1;
    ll ng = N;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(N, M, V, P, A, mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok + 1 << endl;

    return 0;
}