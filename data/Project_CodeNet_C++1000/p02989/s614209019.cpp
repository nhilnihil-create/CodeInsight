#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];

  vector<int> imos(100009, 0); // 難易度i未満の問題数
  rep(i, n) imos[d[i] + 1]++;
  for (int i = 1; i < 100009; ++i) imos[i] += imos[i-1];

  int ans = 0;
  for (int k = 0; k < 100009; ++k) if (imos[k] == n / 2) ans++;
  cout << ans << endl;
  return 0;
}