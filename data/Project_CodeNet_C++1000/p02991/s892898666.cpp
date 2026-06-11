#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> ver(n,vector<int>(0));
  for(int i=0; i<m; ++i){
    cin >> u >> v;
    --u; --v;
    ver[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  --s; --t;
  
  vector<vector<bool>> ng(n,vector<bool>(3,false));
  queue<P> que;
  que.push(make_pair(s,0));
  ng[s][0] = true;
  while(!que.empty()){
    int x = que.front().first;
    int dis = que.front().second;
    if(x == t && (dis%3) == 0){
      cout << dis/3 << endl;
      return 0;
    }
    que.pop();
    int ndis = dis+1;
    for(int a: ver[x]){
      if(ng[a][ndis%3]) continue;
      ng[a][ndis%3] = true;
      que.push(make_pair(a,ndis));
    }
  }
  cout << -1 << endl;
}