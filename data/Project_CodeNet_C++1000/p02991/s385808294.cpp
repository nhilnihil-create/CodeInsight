#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;
const ll INF =1e15;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n+1);
    ll dp[100005][3];
    Fill(dp,INF);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);

    }
    int s,t;
    cin>>s>>t;
    dp[s][0]=0;
    queue<pii> que;
    que.push(make_pair(s,0));
    while(!que.empty()){
        pii tmp = que.front();que.pop();
        int nex = (tmp.second+1)%3;
        for(auto v:G[tmp.first]){
            if(dp[v][nex]!=INF) continue;
            dp[v][nex] = dp[tmp.first][tmp.second]+1;
            que.push(make_pair(v,nex));
        }
    }
    if(dp[t][0]==INF){
        cout<<-1<<endl;
    }else{
        cout<<dp[t][0]/3<<endl;
    }
    return 0;
}