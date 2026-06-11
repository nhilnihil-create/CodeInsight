#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N+1);
  for (int i = 0; i < N+1; i++) cin >> A.at(i);
  vector<long long> M(N+1), m(N+1);
  M.at(N) = m.at(N) = A.at(N);
  for (int i = N-1; i >= 0; i--) {
    M.at(i) = M.at(i+1) + A.at(i);
    m.at(i) = (m.at(i+1) + 1) / 2 + A.at(i); 
  }
  if (m.at(0) > 1) { cout << -1 << endl; return 0; }
  long long ans = 0, tmp = 1;
  for (int i = 0; i <= N; i++) {
    ans += tmp;
    tmp = (tmp - A.at(i)) * 2;
    if (i != N && tmp > M.at(i+1)) tmp = M.at(i+1);
  }
  cout << ans << endl;
}