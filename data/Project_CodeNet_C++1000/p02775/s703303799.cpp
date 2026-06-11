#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int infty = 1 << 30;

int main() {
  string str;
  cin >> str;
  reverse(str.begin(), str.end());

  int N = str.size();
  str += "00";

  vector<vector<int>> m{2, vector<int>(N + 3, 0)};
  m[1][0] = infty;
  for (auto i = 0; i <= N+1; ++i) {
    // pay without change
    m[0][i + 1] = min(m[0][i] + str[i] - '0', m[1][i] + (str[i] - '0' + 1));
    // pay with change
    m[1][i + 1] =
        min(m[0][i] + 10 - (str[i] - '0'), m[1][i] + 10 - (str[i] - '0' + 1));
  }

  cout << m[0][N+1] << endl;
  return 0;
}
