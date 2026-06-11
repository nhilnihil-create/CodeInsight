#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> vec(n,vector<int>(0));
  vector<int> d(n,-1);
  for(int i=0; i<n-1; ++i){
    int a, b;
    cin >> a >> b;
    --a, --b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  
  queue<int> que;
  que.push(0);
  d[0] = k;
  while(!que.empty()){
    int x = que.front();
    que.pop();
    int cnt = k-2;
    if(x == 0) ++cnt;
    for(int a: vec[x]){
      if(d[a] != -1) continue;
      if(cnt == 0){
        cout << 0 << endl;
        return 0;
      }
      d[a] = cnt;
      --cnt;
      que.push(a);
    }
  }
  ll ans = 1;
  for(int i=0; i<n; ++i){
    ans *= d[i];
    ans %= MOD;
  }
  cout << ans << endl;
}