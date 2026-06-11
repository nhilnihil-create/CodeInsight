#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll N, K; 
VVL G;
constexpr ll mod = 1e9+7;

ll dfs(ll from, ll to){
    if(K < G[to].size()) return 0;
    ll usable;
    if(from == -1) usable = K - 1;
    else usable = K - 2;
    ll case_num = 1;
    // usable P #children
    for(auto g : G[to]){
        if(g == from) continue;
        case_num *= usable;
        usable--;
        case_num %= mod;
    }
    for(auto g : G[to]){
        if(g == from) continue;
        case_num *= dfs(to, g);
        case_num %= mod;
    }
    return case_num;
}

int main(){
    cin >> N >> K;
    G.resize(N+1);
    rep(i, 0, N-1){
        ll v, u;
        cin >> v >> u;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll ans = K * dfs(-1, 1);
    ans %= mod;
    cout << ans << endl;
    return 0;
}