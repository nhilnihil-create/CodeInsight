#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e5+5;
vector<int>g[maxm];
int mark[maxm][3];
int dp[maxm][3];
int n,m;
int S,T;
void bfs(){
    queue<PI>q;
    mark[S][0]=1;
    dp[S][0]=0;
    q.push({S,0});
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        int yy=(y+1)%3;
        for(int v:g[x]){
            if(!mark[v][yy]){
                mark[v][yy]=1;
                dp[v][yy]=dp[x][y]+1;
                q.push({v,yy});
            }
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    cin>>S>>T;
    bfs();
    if(!mark[T][0]){
        cout<<-1<<endl;
    }else{
        cout<<dp[T][0]/3<<endl;
    }
    return 0;
}
/*
令dp[i][3]表示点S到达点i,步数%3=0,1,2的最短路,
只需要计算出dp[T][0]即可.
bfs一下就行了.
*/
