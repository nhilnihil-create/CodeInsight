#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, q;
    cin >> n >> q;
    vector< vector<ll> > G(n);
    rep(i, 0, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> imos(n, 0), ans(n, 0);
    rep(i, 0, q) {
        ll p, x;
        cin >> p >> x;
        p--;
        imos[p] += x;
    }
    queue<pair<ll,ll>> que;
    que.push({0, 0});
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        ans[q.first] = ans[q.second] + imos[q.first];
        for(auto g : G[q.first]) {
            if(g == q.second) continue;
            que.push({g, q.first});
        }
    }
    rep(i, 0, n) cout << ans[i] << (i == n-1 ? "\n" : " ");
    return 0;
}