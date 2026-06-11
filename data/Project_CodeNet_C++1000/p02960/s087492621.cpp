#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t INT = 1000000007;
  string S;
  cin >> S;
  int length = S.size();
  vector<vector<int64_t>> dp(length + 1, vector<int64_t> (13));
  dp.at(0).at(0) = 1;
  for(int i = 0; i < length; i++) {
    if(S.at(i) != '?') {
      for(int j = 0; j < 13; j++) {
        int a = S.at(i) - '0';
        dp.at(i + 1).at((j * 10 + a) % 13) = dp.at(i).at(j);
      }
    }
    else {
      for(int k = 0; k < 10; k++) {
        for(int j = 0; j < 13; j++) {
          dp.at(i + 1).at((j * 10 + k) % 13) += dp.at(i).at(j);
          dp.at(i + 1).at((j * 10 + k) % 13) %= INT;
        }
      }
    }
  }
  cout << dp.at(length).at(5) << endl;
}