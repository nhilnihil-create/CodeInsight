#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m; scanf("%d %d", &n, &m);
  vector<vector<int> > data(100010);
  for(int i = 0; i < n; i++){
    int a, b; scanf("%d %d", &a, &b);
    data[a].push_back(b);
  }
  
  priority_queue<int> que;
  int ans = 0;
  for(int i = 0; i <= m; i++){
    for(int j = 0; j < data[i].size(); j++) que.push(data[i][j]);
    if(que.empty()) continue;
    ans += que.top();
    que.pop();
  }
  printf("%d\n", ans);
}