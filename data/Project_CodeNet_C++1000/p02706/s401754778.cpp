#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int sum = accumulate(A.begin(), A.end(), 0L);
  cout << ((sum > N) ? -1 : N - sum) << "\n";
}