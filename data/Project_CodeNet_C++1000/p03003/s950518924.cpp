#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t MOD = 1000000000 + 7;
  int N, M;
  cin >> N >> M;
  vector<int64_t> S(N);
  vector<int64_t> T(M);
  for(int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  for(int i = 0; i < M; i++) {
    cin >> T.at(i);
  }
  vector<vector<int64_t>> data(N + 1, vector<int64_t> (M + 1, 0));
  for(int i = 0; i <= N; i++) {
    data.at(i).at(0) = 1;
  }
  for(int i = 0; i <= M; i++) {
    data.at(0).at(i) = 1;
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(S.at(i - 1) == T.at(j - 1)) {
        data.at(i).at(j) = data.at(i).at(j - 1) + data.at(i - 1).at(j);
        data.at(i).at(j) %= MOD;
      }
      else {
        data.at(i).at(j) = data.at(i).at(j - 1) + data.at(i - 1).at(j) - data.at(i - 1).at(j - 1);
        data.at(i).at(j) += MOD;
        data.at(i).at(j) %= MOD;
      }
    }
  }
  cout << data.at(N).at(M) << endl;
}