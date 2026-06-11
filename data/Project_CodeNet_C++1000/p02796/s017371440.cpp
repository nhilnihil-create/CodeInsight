#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = (1 << 30);
ll N, M;
void func()
{
    cin >> N;
    pair<ll, ll> lf[N];
    ll tmp1, tmp2;
    ll ans(N);
    rep(i, 0, N)
    {
        cin >> tmp1 >> tmp2;
        lf[i] = make_pair(tmp1 + tmp2, tmp1 - tmp2);
    }
    sort(&lf[0], &lf[N]);
    ll i = 0;
    while (i < N)
    {
        ll j = 1;
        while (lf[i].first > lf[i + j].second)
        {
            --ans;
            ++j;
        }
        i += j;
    }
    cout << ans << endl;
}
int main()
{
    func();
}