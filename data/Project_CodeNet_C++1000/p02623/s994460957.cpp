#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b)
{
    if (a < b)
    {
        a = b;
    }
}
template <class T1, class T2>
inline void chmin(T1 &a, const T2 &b)
{
    if (a > b)
    {
        a = b;
    }
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;

inline int max_B(const vector<uint64_t> &B, const uint64_t key, const int M)
{
    int left = -1;
    int right = M + 1;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (B[mid] <= key)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int main()
{
    int N, M;
    uint64_t K;
    cin >> N >> M >> K;
    vector<uint64_t> A(N + 1), B(M + 1);
    A[0] = 0;
    B[0] = 0;
    for (int i = 1; i < N + 1; ++i)
    {
        uint64_t num;
        cin >> num;
        A[i] = A[i - 1] + num;
    }
    for (int i = 1; i < M + 1; ++i)
    {
        uint64_t num;
        cin >> num;
        B[i] = B[i - 1] + num;
    }

    ll ans = 0;

    rep(i, N + 1)
    {
        if (K < A[i])
        {
            break;
        }

        int b = max_B(B, K - A[i], M);
        if (b != -1)
        {
            chmax(ans, i + b);
        }
    }
    cout << ans << endl;
}