#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 1000;
  ll num = 0;
  for (int i = 0; i < N - 1; i++) {
    if (A[i] < A[i+1]) {
      ll temp = ans / A[i];
      num += temp;
      ans -= temp * A[i];
      if (i == N - 2) ans += num * A[i+1];
    }
    if (A[i] >= A[i+1]) {
      ans += num * A[i];
      num = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
