#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N_MAX = 300001;
int main()
{
  int n,m,u,vv,s,t,i,j;
  int d[N_MAX];
  vector<int> v[N_MAX];
  queue<int> q;
  cin >> n >> m;
  for(i=0;i<m;i++){
    cin >> u >> vv;
    v[u].push_back(n+vv);
    v[n+u].push_back(2*n+vv);
    v[2*n+u].push_back(vv);
  }
  cin >> s >> t;
  fill(d+1,d+3*n+1,-1);
  d[s]=0;
  q.push(s);
  while(!q.empty()){
    i=q.front(); q.pop();
    for(j=0;j<v[i].size();j++)
      if(d[v[i][j]]<0){
        d[v[i][j]]=d[i]+1;
        q.push(v[i][j]);
        if(v[i][j]==t){
          cout << d[t]/3 << endl;
          return 0;
        }
      }
  }
  cout << "-1" << endl;
  return 0;
}
