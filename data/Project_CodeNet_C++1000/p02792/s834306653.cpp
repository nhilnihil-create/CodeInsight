#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 10) {
    cout << N << endl;
    return 0;
  }
  int64_t res = 0;
  vector<vector<int64_t>> cnt(10, vector<int64_t>(10));
  for (int i = 1; i <= N; ++i) {
    string str = to_string(i);
    int head = str.front() - '0';
    int tail = str.back() - '0';
    ++cnt[head][tail];
  }
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      res += cnt[i][j] * cnt[j][i];
    }
  }
  cout << res << endl;

  return 0;
}
