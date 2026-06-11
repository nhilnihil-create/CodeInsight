#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m; scanf("%d %d", &n, &m);
  priority_queue<ll> que;
  for(int i = 0; i < n; i++){
      ll x; scanf("%lld", &x);
      que.push(x);
  }
  for(int i = 0; i < m; i++){
      int x = que.top(); que.pop();
      que.push(x/2);
  }
  ll ans = 0;
  while(que.size()){
      ans += que.top();
      que.pop();
  }
  printf("%lld\n", ans);
}