#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 1010;
const long long INF = 1LL << 60;

long long dp[MAX][MAX] = {INF};
string s1, s2;

int main() {
  cin >> s1 >> s2;

  int s1_len = (int)s1.length();
  int s2_len = (int)s2.length();

  for (int i = 0; i <= s1_len; ++i) dp[i][0] = i;
  for (int j = 0; j <= s2_len; ++j) dp[0][j] = j;

  for (int i = 0; i < s1_len; ++i) {
    for (int j = 0; j < s2_len; ++j) {
      long long ins_del = min((dp[i + 1][j] + 1), (dp[i][j + 1] + 1));

      long long rep = 0;
      if (s1[i] == s2[j]) {
        rep = dp[i][j];
      } else {
        rep = dp[i][j] + 1;
      }

      dp[i + 1][j + 1] = min(ins_del, rep);
    }
  }

  cout << dp[s1_len][s2_len] << endl;
  return 0;
}

