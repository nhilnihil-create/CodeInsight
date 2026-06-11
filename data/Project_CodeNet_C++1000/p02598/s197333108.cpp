#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int ng = 0, ok = 1e+9;
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    bool is_ok = [&]{
      int n_cut = 0;
      rep(i, N) n_cut += ((A[i] + mid - 1) / mid) - 1;
      return n_cut <= K;
    }();
    if (is_ok) ok = mid; else ng = mid;
  }
  int ans = ok;
  cout << ans << endl;
  return 0;
}