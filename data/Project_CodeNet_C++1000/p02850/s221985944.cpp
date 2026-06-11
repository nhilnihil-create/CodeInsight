#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 1e5;
  cin >> n;
  vector<vector<int>> tree(n);
  int c[max_n + 1] = {};
  vector<pair<int, int>> vp;
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
    vp.push_back(make_pair(a,b));
  }
  int k = 0;
  for(int i = 0; i < n; i++){
    int size = tree.at(i).size();
    k = max(k, size);
  }
  cout << k << endl;

  queue<int> todo;
  vector<int> seen(n, 0);
  vector<int> cs(n, 0);
  map<pair<int, int>, int> I;

  todo.push(0);
  seen[0] = 1;
  while(!todo.empty()){
    int now = todo.front(); todo.pop();
    int cnt = 1;
    for(auto next: tree[now]){
      if(seen[next] == 1) continue;
      if(cnt == cs[now]) cnt ++;
      cs[next] = I[make_pair(now, next)] = I[make_pair(next, now)] = cnt++;
      seen[next] = 1;
      todo.push(next);
    }
  }
  for(auto i: vp) cout << I[i] << endl;

  return 0;
}