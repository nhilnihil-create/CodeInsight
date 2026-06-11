#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define point complex<long long>
#define pi acos(-1)
#define pb push_back


typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, m, s, e;
vector<int>arr[100005];
int bfs(){
    queue<pair<int,int> >q;
    q.push({s, 0});
    int vis[n+1][3]={0};
    while(!q.empty()){
        int cur=q.front().first, d=q.front().second;
        q.pop();
        if(cur==e && d%3==0)
            return d/3;
            vis[cur][d%3]=1;
        for(auto i: arr[cur]){
            if(vis[i][(d+1)%3])continue;
            vis[i][(d+1)%3]=1;
            q.push({i, d+1});
        }
    }
    return -1;
}
int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int u, v; cin>>u>>v;
            arr[u].pb(v);
        }
        cin>>s>>e;
        cout<<bfs()<<'\n';
    }

    return 0;
}
