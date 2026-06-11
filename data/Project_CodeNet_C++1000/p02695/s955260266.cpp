#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[50];
int b[50];
int c[50];
int d[50];

int rec(vector<int>& v) {
  if (v.size() == n) {
    int sum = 0;
    for (int i = 0; i < q; ++i) {
      if (v[b[i]] - v[a[i]] == c[i]) {
        sum += d[i];
      }
    }
    return sum;
  }
  
  int mn = v.empty() ? 1 : v.back();
  int ans = 0;
  for (int j = mn; j <= m; ++j) {
    v.push_back(j);
    ans = max(ans, rec(v));
    v.pop_back();
  }
  return ans;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }
  
  vector<int> v;
  cout << rec(v) << endl;
}