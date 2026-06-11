#include<bits/stdc++.h>
using namespace std;


int main (void){
  long long int n = 0,m = 0,s = 0,t = 0;
  cin >> n >> m;
  vector<vector<long long int>> g(n,vector<long long int>());

  for(int i = 0;i < m;i++){
    long long int a = 0,b = 0;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }
  cin >> s >> t;
  s--;
  t--;

  queue<pair<int,int>> que;
  vector<vector<long long int>> dist(n,vector<long long int>(4,-1));
  dist[s][0] = 0;
  pair<int,int> cur;
  int l = 0;

  que.push({s,0});

  while(!que.empty()){
    if(dist[t][0] != -1){break;}
    cur = que.front();
    que.pop();
    l = (cur.second + 1) % 3;


    for(int i = 0;i < g[cur.first].size();i++){
      if(dist[t][0] != -1){break;}
      if(dist[g[cur.first][i]][l] == -1){
        que.push({g[cur.first][i],cur.second+1});
        dist[g[cur.first][i]][l]++;
      }
    }
  }

  if(dist[t][0] == -1){
    cout << -1 << endl;
  }else{
    cout << (cur.second + 1) / 3 << endl;
  }
  return 0;

}