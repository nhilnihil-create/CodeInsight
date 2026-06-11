#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> a(n + 1, vector<int>(2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      int ii = i - j - 1;
      for (int jj = 0; jj < 2; ++jj) {
        if (ii - jj < 0) {
          continue;
        }
        if (s.substr(ii - jj, jj + 1) == s.substr(i - j, j + 1)) {
          continue;
        }
        a[i][j] = max(a[i][j], a[ii][jj] + 1);
      }
    }
  }
  cout << max(a[n][0], a[n][1]) << endl;
  return 0;
}
