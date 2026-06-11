#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int binary_search(int N, int K, vector<int> &A) {
  double eps = 1e-6;
  double ng = 0, ok = 1e+9 + 1;

  while (ok - ng > eps) {
    double mid = (ok + ng) / 2;
    int n_cut = 0;
    for (int a: A) {
      n_cut += (int) ceil(a / mid) - 1;
    }
    if (n_cut <= K) {
      ok = mid;
    }
    else {
      ng = mid;
    }
  }
  return (int) ceil(ng);
}


int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int ans = binary_search(N, K, A);
  cout << ans << endl;
  return 0;
}