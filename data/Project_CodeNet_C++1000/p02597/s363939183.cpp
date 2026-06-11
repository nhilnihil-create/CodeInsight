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
    ll N;
    cin >> N;
    string c;
    cin >> c;
    ll w_cnt = 0;
    ll r_cnt = 0;
    rep(i, c.size())
    {
        if (c[i] == 'W')
        {
            ++w_cnt;
        }
        else
        {
            ++r_cnt;
        }
    }

    ll ans = 0;
    rep(i, r_cnt)
    {
        if (c[i] == 'W')
        {
            ++ans;
        }
    }
    cout << ans << endl;
}