#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<vector<char>> S(N, vector<char>(10));
  for (int i = 0; i < N; i++) {
    cin >> S.at(i).at(0) >> S.at(i).at(1) >> S.at(i).at(2) >> S.at(i).at(3) >> S.at(i).at(4) >> S.at(i).at(5) >> S.at(i).at(6) >> S.at(i).at(7) >> S.at(i).at(8) >> S.at(i).at(9);
    sort(S.at(i).begin(), S.at(i).end());
  }
  sort(S.begin(), S.end());
  int64_t ans = 0;
  int64_t memo = 1;
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i).at(0) == S.at(i + 1).at(0) && S.at(i).at(1) == S.at(i + 1).at(1) && S.at(i).at(2) == S.at(i + 1).at(2) && S.at(i).at(3) == S.at(i + 1).at(3) && S.at(i).at(4) == S.at(i + 1).at(4) && S.at(i).at(5) == S.at(i + 1).at(5) && S.at(i).at(6) == S.at(i + 1).at(6) && S.at(i).at(7) == S.at(i + 1).at(7) && S.at(i).at(8) == S.at(i + 1).at(8) && S.at(i).at(9) == S.at(i + 1).at(9)) {
      memo++;
    }
    else {
      ans += (memo * (memo - 1)) / 2;
      memo = 1;
    }
  }
  ans += (memo * (memo - 1)) / 2;
  cout << ans << endl;      
}