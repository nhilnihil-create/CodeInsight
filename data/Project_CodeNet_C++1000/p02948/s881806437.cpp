#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  pair<int, int> ab[n];
  for (int i=0; i<n; i++) cin>>ab[i].first>>ab[i].second;
  sort(ab, ab + n);
  long long ans = 0;
  priority_queue<int> pq;
  int idx = 0;
  for (int i=m-1; i>=0; i--) {
    while (idx < n && ab[idx].first <= m - i) {
      pq.push(ab[idx].second);
      ++idx;
    }
    if (!pq.empty()) {
      int top = pq.top();
      pq.pop();
      ans += top;
    }
  }
  cout<<ans<<endl;
}