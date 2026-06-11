#include <bits/stdc++.h>

using namespace std;
typedef uint64_t u64;
typedef int64_t i64;
typedef double db;

int main() {
  i64 N, X, Y;
  cin >> N >> X >> Y;
  
  vector<i64> k_arr(N + 1);
  for (i64 i = 1; i <= N-1; i++) {
    for (i64 j = i+1; j <= N; j++) {
      i64 l = INT64_MAX;
      l = min(l, abs(i - j));
      l = min(l, abs(i - X) + 1 + abs(Y - j));
      l = min(l, abs(i - Y) + 1 + abs(X - j));
      k_arr[l]++;
    }
  }
  for (int i = 1; i <= N-1; i++) {
    cout << k_arr[i] << endl;
  }
  return 0;
}