#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n+1);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<bool> used(n+2, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++)
  	{
    if (!used[i]){
      used[i] = true;
      ans++;
      queue<int> q;
      q.push(i);
      while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int &w : a[v]){
          if (!used[w]){
            used[w] = true;
            q.push(w);
          }
        }
      }
    }
  }

  cout << ans - 1 << endl;
}
