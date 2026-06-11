#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  priority_queue<pair<int ,int>> q;
  for(int i = 0; i < n; i++){
    cin >> b[i];
    q.push({b[i], i});
  }

  int ans = 0;
  while(!q.empty()){
    auto p = q.top(); q.pop();
    int idx = p.second;
    int left = (idx - 1 + n) % n, right = (idx + 1) % n;
    int diff = (b[idx] - a[idx]) / (b[left] + b[right]);
    int val = b[idx] - (b[left] + b[right]) * diff;
    if(diff == 0 || val < a[idx]) continue;
    b[idx] = val;
    q.push({val, idx});
    ans += diff;
  }
  if(a != b) ans = -1;
  cout << ans << endl;

  return 0;
}
