#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;

int N,K;
vector<vector<int> > G(100010);
vector<ll> color(100010,0);   // v で使える色の種類数

void dfs(int p, int v){
    int k = color[v];

    if(k <= K-2) k = K-1;

    int cnt = 1;
    for(auto nv: G[v]){
        if(nv == p) continue;
        color[nv] = k-cnt;
        dfs(v, nv);
        cnt++;
    }
    return;
}

int main(){
    cin >> N >> K;
    rep(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color[0] = K;
    dfs(-1, 0);

    ll res = 1;
    rep(i,N) {
        res *= color[i];
        res %= MOD;
    }
    res = max((ll)0,res);
    cout << res << endl;
}
