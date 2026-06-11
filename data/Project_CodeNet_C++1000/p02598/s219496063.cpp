#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool check(const vector<int>& A, long long K, long long m) {
  long long count = 0;
  for (size_t i = 0; i < A.size(); i++) {
    // add smallest k s.t. A[i]/k <= m to count
    long long k = (A[i] - 1) / m;
    count += k;
  }
  return (count <= K);
}

int main(void) {
  long N, K;
  cin >> N >> K;
  vector<int> A(N);
  int l = 1, u = 0;
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
    u = max(u, A[i]);
  }
  while (true) {
    if (l == u) break;
    long long m = (l + u) / 2;
    // cout << l << "," << u << "," << m << endl;
    if (check(A, K, m)) {  // m can be achieved
      u = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << endl;
  return 0;
}