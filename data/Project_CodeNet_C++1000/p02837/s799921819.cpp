#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

bool XOR(bool a, bool b){ return (a + b) % 2; }

int main() {
  // 小数点以下10桁まで
  // cout << fixed << setprecision(10);

  int N;
  std::cin >> N;
  std::vector<int> A(N);
  vector<vector<int>> x(N, vector<int>(N));
  vector<vector<int>> y(N, vector<int>(N));
  for (size_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    for (size_t j = 0; j < A.at(i); j++) {
      std::cin >> x.at(i).at(j) >> y.at(i).at(j);
      x.at(i).at(j) -= 1;
    }
  }

  int maximum = 0;
  // {0, 1, ..., N-1} の部分集合の全探索
  // 1が正直者、0が不親切な人
  for (size_t bit = 0; bit < (1<<N); bit++) {
    bool alright = true;
    int honest = 0;
    for (size_t i = 0; i < N; i++) {
      if (bit & 1<<i) {
        honest += 1;
        for (size_t j = 0; j < A.at(i); j++) {
          if (XOR(bit & 1<<x.at(i).at(j), y.at(i).at(j) == 1)) alright = false;
        }
      }
    }
    if (alright) maximum = max(maximum, honest);
  }

  cout << maximum << endl;
}
