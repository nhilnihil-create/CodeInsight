#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<int> diff;
  for (int i = 0; i < N; i++) {
    diff.push_back((A[(i+1)%N] + K - A[i]) % K);
  }
  int ans = K - *max_element(diff.begin(), diff.end());
  cout << ans << '\n';
  return 0;
}