#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const ll INF = 1LL << 60;

int main()
{
    ll N;
    cin >> N;
    vector<ll> d;
    rep(i, N)
    {
        ll tmp;
        cin >> tmp;
        d.emplace_back(tmp);
    }

    sort(d.begin(), d.end());

    ll ans = d[N / 2] - d[N / 2 - 1];

    cout
        << ans << endl;

    return 0;
}
