#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long n, a[100010];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int idx = 0;
  vector<pair<int, int>> ans;

  while(a[idx] < 0) idx++;
  if(idx == 0) {
    for(int i = 1; i < n-1; ++i) {
      ans.emplace_back(a[0], a[i]);
      a[0] -= a[i];
    }
    ans.emplace_back(a[n-1], a[0]);
    a[n-1] -= a[0];
  } else if(idx == n) {
    for(int i = 0; i < n-1; ++i) {
      ans.emplace_back(a[n-1], a[i]);
      a[n-1] -= a[i];
    }
  } else {
    for(int i = idx; i < n-1; ++i) {
      ans.emplace_back(a[0], a[i]);
      a[0] -= a[i];
    }
    for(int i = 0; i < idx; ++i) {
      ans.emplace_back(a[n-1], a[i]);
      a[n-1] -= a[i];
    }
  }
  cout << a[n-1] << endl;
  for(auto p : ans) cout << p.first << " " << p.second << endl;
  return 0;
}