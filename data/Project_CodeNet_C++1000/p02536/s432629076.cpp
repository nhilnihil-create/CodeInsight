

#include <bits/stdc++.h>

#define MAX 10000
using namespace std;
#define inf    0x3f3f3f3f
#define ll long long
#define all(a) (a).begin(),(a).end()
#define INF (int)1e15
#define MOD 1000000007
#define access(i) a[i/3][i%3]

using namespace std;

const int maxi = 1e5+7;

vector< vector<int> >adj(maxi);

 int cnt=0;
 int ani[maxi] ;

 void dfs(int node){

  ani[node] = 1;

   for(int j=0;j<adj[node].size();j++)
    {
     if(! ani[adj[node][j]]){
        dfs(adj[node][j]);
     }
   }

 }

int main()
{
    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
       if(!ani[i]){
            dfs(i);
            cnt++;
        }
    }

  cout<<cnt-1<<endl;

 return 0;
}