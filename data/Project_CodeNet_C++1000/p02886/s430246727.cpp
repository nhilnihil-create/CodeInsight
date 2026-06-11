#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  int ans = 0;  
  rep(i, N) rep(j, i) {
    ans += D[i] * D[j];
  }
  cout << ans << '\n';
  
  return 0;
}