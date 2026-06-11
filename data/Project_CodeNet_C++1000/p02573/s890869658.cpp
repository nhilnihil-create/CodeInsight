


#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 vector<int>v[200005];
 bool vis[200005];

 int bfs(int x){

   queue<int>Q;
   Q.push(x);
   int cnt=0;

   while(!Q.empty()){
       int first = Q.front();
       Q.pop();

       if(vis[first]) continue;
       vis[first] = true , cnt++;

       for(int u:v[first])
            Q.push(u);

      }

      return cnt;
 }

 int main(){

 ll n,m; cin>>n>>m;

 memset(vis,false,sizeof(vis));

 for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a; b;
      a--; b--;

 v[a].push_back(b);
 v[b].push_back(a);
 }

//  vector<int>::iterator it = v.begin();

/*
  for(int i=0;i<n;i++){
      cout<<i<<"->";
      for(int j=0;j<v[i].size();j++)
      {
            if(j == v[i].size() - 1)
                    cout << v[i][j] << endl;
            else
                cout << v[i][j] << " --> ";
      }
      cout<<endl;
   }

   */

  int ans = bfs(0);

  // cout<<"ecnerwala "<<ans<<endl;

  for(int i=0;i<n;i++){
     if(!vis[i]){
      int cnt = bfs(i);

        if(cnt > ans)
            ans = cnt;

     }
  }

  cout<<ans<<endl;

 return 0;
 }