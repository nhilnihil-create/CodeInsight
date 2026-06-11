#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<vector<pair<int, int> > > v(n + 1);
  //vector<pair<int, int> e(n);
  for(int i = 1; i < n; i++){
    int a, b; cin >> a >> b;
    //e[i] = make_pair(a, b);
    v[a].push_back(make_pair(b, i));
    v[b].push_back(make_pair(a, i));
  }

  vector<set<int> > cl(n + 1);
  vector<int> visited(n + 1, false), pc(n + 1), p(n + 1), ans(n + 1);

  queue<int> q;
  q.push(1);

  pc[1] = -1;
  p[1] = -1;
  int c, nx, maxj = 0, en;
  while(q.size() > 0){
    c = q.front();
    q.pop();
    int j = 1;
    for(int i = 0; i < v[c].size(); i++){
      nx = v[c][i].first;
      en = v[c][i].second;
      if(nx == p[c]) continue;
      if(j == pc[c]) j++;
      cl[c].insert(j);
      pc[nx] = j;
      p[nx] = c;
      ans[en] = j;
      maxj = max(maxj, j);
      j++;
      q.push(nx);
    }
  }
  cout << maxj << endl;
  for(int i = 1; i < n; i++){
    cout << ans[i] << endl;
  }
  /*for(int i = 1; i <= n; i++){
    cout << i << " -> ";
    for(auto it = cl[i].begin(); it != cl[i].end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }*/
  return;
}

int main(){
  solve();
  return 0;
}
