#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, D, A;
vector<P> v;
int main() {
    cin >> N >> D >> A;
    v.resize(N);
    rep(i, N) {
        ll x, h;
        cin >> x >> h;
        v[i] = P(x, h);
    }
    sort(v.begin(), v.end());

    queue<P> que;
    D = 2 * D;
    ll ans = 0;
    ll before_damage = 0;

    rep(i, N) {
        ll x2 = v[i].first;
        ll h2 = v[i].second; 

        // 爆風で与えるダメージ
        while (que.size() > 0 && que.front().first < x2) {
            before_damage -= que.front().second;  
            que.pop();
        }

        h2 -= before_damage;

        // 何回必要か
        if (h2 > 0) {
            ll cnt = ceil((double)h2 / A);
            ans += cnt;
            ll damage = cnt * A;
            before_damage += damage;

            que.push(P(x2 + D, damage));
        }
    }
    cout << ans << endl;
}