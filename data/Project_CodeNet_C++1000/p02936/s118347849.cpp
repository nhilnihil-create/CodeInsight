#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

ll MAX = 2*(1e5);

vector<vector<ll>> V(MAX);
vector<ll> C(MAX, 0);
vector<bool> vis(MAX, false);


int dfs(int x){
    for(auto v : V[x]){
        if(!vis[v]) {
            vis[v] = true;
            C[v] += C[x];
            dfs(v);
        }
    }
    return 0;
}

int main(){
    ll N, Q; cin >> N >> Q;

    for(int i = 0; i < N-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i = 0; i < Q; i++){
        ll p, x; cin >> p >> x;
        p--;
        C[p]+=x;
    }
    vis[0] = true;
    dfs(0);
    for(int i = 0; i < N; i++) cout << C[i] << " ";
    cout << endl;




}
