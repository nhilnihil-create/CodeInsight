#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  double sum = 0;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  int cnt = 0;
  rep(i, N) {
    if (A[i] >= (double)(sum / (4 * M))) cnt++;
  }
  if (cnt >= M)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}