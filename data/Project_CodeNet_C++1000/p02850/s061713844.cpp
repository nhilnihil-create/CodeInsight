#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int n; cin>>n;
    vector<vector<int>> G(n);
    vector<pair<int,int>> vp;
    for(int i=1;i<n;i++){ //辺はn-1個ある
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a,b);
    }

    //グラフ作成終わり

    int k=0;
    map<pair<int,int>,int> I;
    vector<int> cs(n,0);

    vector<int> used(n,0);
    queue<int> que;
    used[0]=1;
    que.emplace(0);
    while(!que.empty()){
        int v=que.front(); que.pop();
        if(k<(int)G[v].size()) k=G[v].size();
        int color=1;
        for(int u:G[v]){
            if(used[u])continue;
            if(color==cs[v]) color++;
            cs[u]=color;
            I[make_pair(u,v)]=color;
            I[make_pair(v,u)]=color;
            color++;
            used[u]=1;
            que.emplace(u);
        }
    }

    cout<<k<<endl;
    for(auto p:vp) cout<<I[p]<<endl;
    return 0;
}