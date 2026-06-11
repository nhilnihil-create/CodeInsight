#include<bits/stdc++.h>
using namespace std;



int main(){
  int n;
  cin >> n;
  vector<vector<pair<int,int>>> g(n);
  for(int i=0;i<n-1;++i){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(make_pair(b,i));
    g[b].push_back(make_pair(a,i));
  }

  queue<pair<int,int>> que;
  vector<int> dist(n,-1);
  dist[0]=0;
  que.push(make_pair(0,-1));
  vector<int> color(n-1,-1);
  map<int,int>mp;

  while(!que.empty()){
    auto p=que.front();
    que.pop();
    int c=p.second;
    int v=p.first;
    int col=1;
    if(col==c)++col;
    for(auto nv : g[v]){
      if(dist[nv.first]!=-1) continue;

      dist[nv.first]=dist[v]+1;
      que.push(make_pair(nv.first,col));
      color[nv.second]=col;
      mp[col]++;
      col++;
      if(col==c)++col;
    }
  }
  cout << mp.size() << endl;
  for(auto v : color) cout << v << endl;

  return 0;
}
