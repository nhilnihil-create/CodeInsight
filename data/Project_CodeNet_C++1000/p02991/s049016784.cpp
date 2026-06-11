#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int INF = (1LL<<31)-1;

int N,M,s,t;
vector<vector<int> > G(100010);
vector<vector<int> > d(100010,vector<int>(3,-1));
void bfs(int s){
    d[s][0] = 0;
    queue<P> que; que.push({s,0});
    while(!que.empty()){
        P q = que.front();
        que.pop();
        int v = q.first;
        int parity = q.second;
        for(auto nv : G[v]){
            int np = (parity + 1) % 3;
            if(d[nv][np]==-1){
                que.push({nv,np});
                d[nv][np] = d[v][parity]+1;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    rep(i,M){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
    }
    cin >> s >> t;

    bfs(s);
    if(d[t][0]==-1) cout << "-1" << endl;
    else cout << d[t][0]/3 << endl;
}