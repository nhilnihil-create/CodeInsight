#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 今までの最小値の個数
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int mi = 1e6;
  int ans = 0;  
  rep(i, N) {
    if (A[i] < mi) {
      mi = A[i];
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}