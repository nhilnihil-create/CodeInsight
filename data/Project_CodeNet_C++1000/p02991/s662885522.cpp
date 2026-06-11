#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

int main() {
  int N,M,u,v,S,T;
  cin >> N >> M;
  vector<vector<int>> g(N);
  rep(i,M) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }
  cin >> S >> T;
  S--;T--;

  priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
  vector<vector<ll>> ans(N,vector<ll> (3,LONG_LONG_MAX/100));
  pq.push({0,S,0});//距離、場所、状態,from

  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    if (ans[t[1]][t[2]]>t[0]){
      ans[t[1]][t[2]] = t[0];
      for (auto e:g[t[1]]) {
        pq.push({t[0] + 1 ,e ,(t[2]+1)%3});
      }
    }
  }
  int res = LONG_LONG_MAX/100>ans[T][0]?ans[T][0]/3:-1;
  cout << res << endl;
}