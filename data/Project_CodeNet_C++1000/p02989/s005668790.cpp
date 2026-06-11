#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // Nは偶数
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  sort(D.begin(), D.end());
  int diff = D[N/2] - D[N/2 - 1];
  cout << diff << '\n';
  return 0;
}