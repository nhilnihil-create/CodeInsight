#include <bits/stdc++.h>
using namespace std;

struct data {
  long long d, c;
};

long long m;
vector<data> v;

long long solve();

int main() {
  cin >> m;
  v.resize(m);
  for(int i = 0; i < m; ++i) cin >> v[i].d >> v[i].c;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0, sum = 0;
  for(int i = 0; i < m; ++i) ans += v[i].c;
  for(int i = 0; i < m; ++i) sum += v[i].d * v[i].c;
  return ans - 1 + (sum - 1) / 9;
}