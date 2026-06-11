#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N), B(N);
  for(int i = 0; i < N; i++) {
    int64_t x, y;
    cin >> x >> y;
    A.at(i) = x + y;
    B.at(i) = x - y;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  cout << max(A.at(N - 1) - A.at(0), B.at(N - 1) - B.at(0)) << endl;
}