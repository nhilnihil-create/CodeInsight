#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll u[N],m[N],b[N];
vector<vector<int> > adj;
bool visited[N][10]={};
int nodesNum;
int s,t;
int bfs(int node)
{
   queue<pair<int,int> > q;
   q.push({node,0});
   visited[node][0] = 1;
   while (!q.empty())
   {
       node = q.front().first;
       int dist=q.front().second;
       if(node==t&&(dist)%3==0)return dist/3;
       q.pop();
       for (int i=0;i< adj[node].size();i++){
            int child=adj[node][i];
         if (!visited[child][(dist+1)%3])
           {
               q.push({child,dist+1});
               visited[child][(dist+1)%3] = 1;
           }
       }

   }
   return -1;

}

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

int n,m;
cin>>n>>m;
adj.resize(n+5);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}

cin>>s>>t;
cout<<bfs(s);

    return 0;
}
