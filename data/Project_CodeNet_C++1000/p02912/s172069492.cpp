#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N, M;
  cin >> N >> M;
  
  priority_queue<ll> que;
  for(int i=0; i<N; i++){
    ll A; cin >> A;
    que.push(A);
  }
  
  for(int i=0; i<M; i++){
    ll b = que.top(); que.pop();
    que.push(b/2);
  }
  
  ll res = 0;
  while(!que.empty()) res += que.top(), que.pop();
  cout << res << endl;
  
  return 0;
}
