#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll n;
vector<vector<pair<ll,ll>>> G;
vector<ll> color;

void dfs(ll cur, ll from) {
    ll c = 1;
    for(auto g : G[cur]) {
        if(g.second == from) continue;
        while(c == color[from]) c++;
        color[g.second] = c++;
        dfs(g.first, g.second);
    }
}

int main(){
    cin >> n;
    G.resize(n);
    color.resize(n-1);
    rep(i, 0, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    dfs(0, -1);
    cout << *max_element(color.begin(), color.end()) << endl;
    rep(i, 0, n-1) cout << color[i] << "\n";
    return 0;
}