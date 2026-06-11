//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> path(n);
    rep(i,m){
        int u,v; cin>>u>>v;
        u--; v--;
        path[u].push_back(v);
    }
    int s,t,p,P; cin>>s>>t;
    s--; t--;
    vector<int> dis(n,-1);
    vector<vector<int>> visited(2,vector<int>(n,0));
    dis[s]=0;
    queue<int> que;
    que.push(s);
    while(!(que.empty())){
        p=que.front();
        que.pop();
        vector<queue<int>> q(2);
        for(auto to:path[p]){
            if(visited[0][to]) continue;
            visited[0][to]=1;
            q[0].push(to);
        }
        while(!(q[0].empty())){
            P=q[0].front();
            q[0].pop();
            for(auto to:path[P]){
                if(visited[1][to]) continue;
                visited[1][to]=1;
                for(auto TO:path[to]){
                    if(dis[TO]==-1){
                        dis[TO]=dis[p]+1;
                        que.push(TO);
                    }
                }
            }
        }
    }
    cout<<dis[t]<<endl;
}