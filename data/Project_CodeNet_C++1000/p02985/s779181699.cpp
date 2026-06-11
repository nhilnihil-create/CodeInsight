#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll n,k;
vector<vector<ll>> graph(1e5);
const ll MOD = 1e9+7;
ll ans = 1;

vector<bool> vdist(1e5,false);
vector<ll> kaizyou(1e5+2,1);
vector<ll> kaizyouinv(1e5+2,1);

ll inv_mod(ll a, ll MOD)
{
    ll b = MOD, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t*b;   swap(a,b);
        u -= t*v;   swap(u,v);
    }
    u %= MOD;
    if(u < 0) u+= MOD;
    return u;
}

void dfs(ll now)
{
    vdist.at(now) = true;
    if(graph.at(now).size()-1 > k-2){
        ans = 0;
        return;
    }else{
        ans *= kaizyou.at(k-2);
        ans %= MOD;
        ans *= kaizyouinv.at(k-2-(graph.at(now).size()-1));
        ans %= MOD;
        for(auto next:graph.at(now)){
            if(!vdist.at(next)) dfs(next);
        }
    }
    return;
}

int main()
{
    ll i,j;
    kaizyou.at(0) = 1;
    kaizyou.at(1) = 1;
    for(i = 2;i < kaizyou.size();++i){
        kaizyou.at(i) = kaizyou.at(i-1)*i%MOD;
    }
    kaizyouinv.at(0) = 1;
    kaizyouinv.at(1) = inv_mod(1, MOD);
    for(i = 2;i < kaizyouinv.size();++i){
        kaizyouinv.at(i) = kaizyouinv.at(i-1)*inv_mod(i, MOD)%MOD;
    }
    cin >> n >> k;
    
    for(i = 0;i < n-1;++i){
        ll a,b;
        cin >> a >> b;
        --a;    --b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    vdist.at(0) = true;
    ans *= k;
    ans %= MOD;
    if(graph.at(0).size() > k-1){
        cout << 0 << endl;
        return 0;
    }else{
        ans *= kaizyou.at(k-1);
        ans %= MOD;
        ans *= kaizyouinv.at(k-1-graph.at(0).size());
        ans %= MOD;
    }
    for(auto next:graph.at(0)){
        if(!vdist.at(next)) dfs(next);
    }
    cout << ans << endl;
    return 0;
}