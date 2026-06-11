#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> g(200005);
vector<ll> ans;
void dfs(ll v, ll p = -1){
    for(ll u : g.at(v)){
        if(u == p)
            continue;
        ans.at(u) += ans.at(v);
        dfs(u, v);
    }
}
int main(){
    ll n, q;
    cin >> n >> q;
    for(ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }
    ans.resize(n);
    for(ll i = 0; i < q; i++){
        ll p, x;
        cin >> p >> x;
        p--;
        ans.at(p) += x;
    }
    dfs(0);
    for(ll i = 0; i < n; i++)
        cout << ans.at(i) << " ";
    return 0;
}