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

inline bool C(ll num, ll K, const vl &A)
{
    ll sum = 0;
    for (auto a : A)
    {
        sum += (a - 1) / num;
        if (sum > K)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vl A(N);
    rep(i, N) cin >> A[i];
    sort(all(A), greater<ll>());

    ll lb = 1;
    ll ub = A[0] + 1;
    while (ub - lb > 1)
    {
        ll mid = (lb + ub) / 2;
        if (C(mid, K, A))
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }
    if (C(lb, K, A))
    {
        cout << lb << endl;
    }
    else
    {
        cout << ub << endl;
    }
}