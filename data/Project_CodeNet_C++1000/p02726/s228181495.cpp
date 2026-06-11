#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int>> M(n);
  for(int i = 0; i < n; i++){
    if(i < n-1) M.at(i).push_back(i+1);
    if(i > 0) M.at(i).push_back(i-1);
  }
  M.at(x-1).push_back(y-1); M.at(y-1).push_back(x-1);
  
  vector<int> ans(n,0);
  for(int i = 0; i < n; i++){
    vector<int> dist(n,-1);
    queue<int> que;
  
    dist.at(i) = 0;
    que.push(i);
  
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(int nv : M.at(v)){
        if(dist.at(nv) != -1) continue;
        dist.at(nv) = dist.at(v) + 1;
        que.push(nv);
      }
    }
    for(int i = 0; i < n; i++) ans.at(dist.at(i))++;
  }
  
  for(int i = 1; i < n; i++) cout << ans.at(i)/2 << endl;
  return 0;
}