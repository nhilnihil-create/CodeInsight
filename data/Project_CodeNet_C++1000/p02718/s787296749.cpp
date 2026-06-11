#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int sum = 0;
  vector<int> A(N);
  rep(i,0,N-1)
  {
    cin >> A[i];
    sum += A[i];
  }

  sort(begin(A), end(A), greater<int>());
  double required = sum / 4.0 / M;

  bool ok = true;
  rep(i,0,M-1)
    if (A[i] < required)
      ok = false;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
