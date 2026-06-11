
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

template <class T>
using vec = vector<T>;
template <class T>
using vec2 = vector<vec<T>>;
template <class T>
using vec3 = vector<vec2<T>>;

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
constexpr ll MOD = 1000000007; // 10^9+7

#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

int N;
int K;
vec<ll> A;

ll solve()
{
    ll ok = *max_element(A.begin(), A.end()) + 2;
    ll ng = 0;
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;

        int cnt = 0;
        rep(i, N)
        {
            cnt += (A[i] + mid - 1) / mid - 1;
        }

        if (cnt <= K)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main()
{
    cin >> N >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    cout << solve() << endl;
    return 0;
}
