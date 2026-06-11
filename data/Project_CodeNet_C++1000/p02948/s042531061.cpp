#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  int N, M;
  cin >> N >> M;
  
  ll A[N], B[N];
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  
  vector<vector<ll>> G(M+1);
  
  for (int i = 0; i < N; i++){
    if (A[i] <= M) G[A[i]].push_back(B[i]);
  }
  
  ll ans = 0;
 
  priority_queue<ll> pq; 
  for (int i = M-1; i >= 0; i--) { 
    for (ll j : G[M-i]) pq.emplace(j); 
    if (!pq.empty()) {  
      ans += pq.top();
      pq.pop();
    }
  }
  
  cout << ans << endl;
  
}