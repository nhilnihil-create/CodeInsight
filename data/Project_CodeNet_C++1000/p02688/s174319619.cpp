#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

int main() {
  i64 N, K;
  cin >> N >> K;
  vector<i64> R(N, 1);
  for (i64 i = 0; i < K; i++) {
    i64 d;
    cin >> d;
    for (i64 j = 0; j < d; j++) {
      i64 u;
      cin >> u;
      R[u - 1] = 0;
    }
  }
  i64 r = accumulate(R.begin(), R.end(), 0);
  cout << r << endl;
}
