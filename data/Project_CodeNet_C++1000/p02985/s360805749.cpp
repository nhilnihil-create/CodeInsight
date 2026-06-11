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
constexpr ll mod = 1e9+7;

ll N, K;
VVL G;

ll dfs(ll from, ll now){
    if(K < G[now].size()) return 0;
    ll usable;
    if(from == -1) usable = K-1;
    else usable = K - 2;
    ll comb = 1;
    if(from == -1){
        rep(i, 0, G[now].size()){
            comb *= (usable - i);
            comb %= mod;
        }
    }else{
        rep(i, 0, G[now].size()-1){
            comb *= (usable - i);
            comb %= mod;
        }
    }
    ll ret = 1;
    for(auto g : G[now]){
        if(g == from) continue;
        ret *= dfs(now, g);
        ret %= mod;
    }
    ret *= comb;
    ret %= mod;
    return ret;
}

int main(){
    cin >> N >> K;
    G.resize(N);
    rep(i, 0, N-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << (K * dfs(-1, 0)) % mod << endl;
    return 0;
}