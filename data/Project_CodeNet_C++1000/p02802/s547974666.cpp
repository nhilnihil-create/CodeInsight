#include <bits/stdc++.h>

using namespace std;
typedef uint64_t u64;
typedef int64_t i64;
typedef double db;

int main() {
  i64 N, M;
  cin >> N >> M;
  vector<i64> successed(N), failed(N);
  for (int i = 0; i < M; i++) {
    int p;
    string s;
    cin >> p >> s;
    if (s[0] == 'A') {
      successed[p-1] = 1;
    } else {
      failed[p-1] += (1 - successed[p-1]);
    }
  }
  for (int i = 0; i < N; i++) {
    failed[i] *= successed[i];
  }
  cout << accumulate(successed.begin(), successed.end(), 0) << ' '
       << accumulate(failed.begin(), failed.end(), 0)
       << endl;
}
