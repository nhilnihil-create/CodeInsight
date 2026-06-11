#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)
using Graph = vector<vector<int>>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int n,m;cin>>n>>m;
    Graph g(n);
    int a[m],b[m];
    rep(i,m){
        cin>>a[i]>>b[i];
        g[a[i]-1].push_back(b[i]-1);
    }
    int s,t;cin>>s>>t;
    s--;t--;
    queue<pair<int,int>> q;
    q.push({s,0});
    int dist[n][3];
    rep(i,n) rep(j,3) dist[i][j]=-1;
    dist[s][0]=0;
    while(!q.empty()){
        int p=q.front().first,qq=q.front().second;q.pop();
        for(auto now:g[p]){
            int qqnow=(qq+1)%3;
            if(dist[now][qqnow]==-1){
                dist[now][qqnow]=dist[p][qq]+1;
                q.push({now,qqnow});
            }
        }
    }
    if(dist[t][0]==-1) cout<<-1<<"\n";
    else cout<<dist[t][0]/3<<"\n";

}