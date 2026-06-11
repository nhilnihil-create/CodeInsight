#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B(*max_element(A.begin(), A.end()) + 1, 0);
  for (int a : A) {
    for (int b = a; b < (int)B.size(); b += a) {
      B[b]++;
    }
  }
  int res = 0;
  for (int a : A) {
    if (B[a] == 1) res++;
  }
  cout << res << '\n';
  return 0;
}
