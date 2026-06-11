#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll,ll>> x_h(n);
    rep(i,n) cin >> x_h[i].first >> x_h[i].second;
    sort(x_h.begin(), x_h.end());

    ll ans = 0, minus = 0, plus = 0;
    queue<pair<ll,ll>> que;
    que.emplace(0LL,0LL);

    rep(i,n) {
        ll x = x_h[i].first;
        while (que.front().first < x && que.size() != 0) {
            plus += que.front().second;
            que.pop();
        }

        ll h = x_h[i].second - minus + plus;
        if (h < 1) continue;

        ll bomb_x = x + d;
        ll bomb_xr = bomb_x + d;

        ll n_bomb = (h + a - 1) / a;
        ans += n_bomb;

        ll total_damage = n_bomb * a;
        minus += total_damage;
        que.emplace(bomb_xr, total_damage);
    }
    cout << ans << endl;
    return 0;
}