#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int n,q;
const int max_n = 2 * 1e5;
vector<vector<int>> tree(max_n + 1);
// int p[max_n + 1], x[max_n + 1];
vector<int> seen(max_n + 1, 0);
vector<int> score(max_n + 1, 0);

void dfs(int now, int sum){
  // cout << "now = " << now << "sum = " << sum << endl;

  for(auto next : tree[now]){
    if(seen[next] == 1) continue;
    seen[next] = 1;
    score[next] += sum;
    dfs(next, score[next]);
  }
  
  return;
}

int main(){
  cin >> n >> q;
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for(int i = 0; i < q; i++) {
    // cin >> p[i] >> x[i];?
    int p,x;
    cin >> p >> x;
    p --;
    score[p] += x;
  }
  
  // cout << "initial score" << endl;
  // for(int i = 0; i < q; i++) cout << score[i] << endl;

  seen[0] = 1;
  dfs(0, score[0]);

  for(int i = 0; i < n; i++){
    cout << score[i] << endl;
  }

  return 0;
}