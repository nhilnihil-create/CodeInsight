#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

void solve(){
  int v, e; cin >> v >> e;
  vector<vector<int> > a(v);
  vector<int> ind(v, 0), c(v, 0), ans;
  for(int i = 0; i < e; i++){
    long long s, t; cin >> s >> t;
    a[s].push_back(t);
    ind[t]++;
  }
  for(int i = 0; i < v; i++){
    if(ind[i] == 0 && c[i] == 0){
      queue<int> q;
      q.push(i);
      c[i] = 1;
      while(q.size() > 0){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int j = 0; j < a[x].size(); j++){
          ind[a[x][j]]--;
          if(ind[a[x][j]] == 0 && c[a[x][j]] == 0){
            q.push(a[x][j]);
            c[a[x][j]] = 1;
          }
        }
      }
    }
  }
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}

