#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n, q;
  cin >> n >> q;
  vector<vector<int>> ver(n,vector<int>(0));
  int a, b;
  for(int i=0; i<n-1; ++i){
    cin >> a >> b;
    --a; --b;
    ver[a].push_back(b);
    ver[b].push_back(a);
  }
  int p, x;
  vector<int> Q(n,0);
  for(int i=0; i<q; ++i){
    cin >> p >> x;
    --p;
    Q[p] += x;
  }
  vector<int> ans(n,-1);
  queue<P> que;
  que.push(make_pair(0,Q[0]));
  while(!que.empty()){
    int y = que.front().first;
    int v = que.front().second;
    que.pop();
    ans[y] = v;
    for(int a:ver[y]){
      if(ans[a] == -1) que.push(make_pair(a,v+Q[a]));
    }
  }
  for(int i=0; i<n; ++i){
    if(i != n-1) cout << ans[i] << " ";
    else cout << ans[i] << endl;
  }
}