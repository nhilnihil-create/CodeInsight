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

int main()
{
    ll K;
    cin >> K;

    ll mod = 0;
    ll cnt = 0;
    ll ans = 0;
    unordered_set<ll> memo;
    while (1)
    {
        ++cnt;
        mod = (mod * 10 + 7) % K;
        if (mod == 0)
        {
            ans = cnt;
            break;
        }
        else
        {
            if (memo.find(mod) != memo.end())
            {
                ans = -1;
                break;
            }
            memo.emplace(mod);
        }
    }
    cout << ans << endl;
}