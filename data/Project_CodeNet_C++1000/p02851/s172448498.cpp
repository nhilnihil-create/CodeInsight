#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  int mod[n];
  for (int i=0; i<n; i++) mod[i] = (a[i] - 1) % k;
  long acc[n+1];
  acc[0] = 0;
  for (int i=0; i<n; i++) {
    acc[i+1] = acc[i] + mod[i];
    acc[i+1] %= k;
  }
  map<long, vector<int>> m;
  for (int i=0; i<n+1; i++) {
    m[acc[i]].push_back(i);
  }
  long long ans = 0;
  for (auto e: m) {
    vector<int> v = e.second;
    for (int i=0; i<v.size(); i++) {
      auto it = upper_bound(v.begin(), v.end(), v[i] + k - 1);
      --it;
      ans += it - v.begin() - i;
    }
  }
  cout<<ans<<endl;
}