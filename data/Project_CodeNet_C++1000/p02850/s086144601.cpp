#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N; cin >> N;
    vector<vector<pll>> g(N);
    rep(i, N-1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    vector<bool> check(N, false);
    queue<ll> que;
    que.push(0);
    check[0] = true;
    vll ans(N-1), pcolor(N, 0);
    ll cnt = 0;
    while(!que.empty()) {
        ll now = que.front();
        que.pop();
        check[now] = true;

        ll color = 1;
        for(auto next: g[now]) {
            ll nn = next.first;
            ll ne = next.second;
            if(check[nn] == true) continue;

            que.push(nn);
            if(color == pcolor[now]) color++;
            ans[ne] = color, pcolor[nn] = color;
            chmax(cnt, color);
            color++;
        }
    }
    cout << cnt << endl;
    rep(i, N-1) cout << ans[i] << endl;
}
