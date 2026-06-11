#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

int n, m, p[100005];
string s[100005];
map<int, vector<string>> memo;

int main() {
  cin >> n >> m;
  vector<string> emp;
  for (int i = 0; i < m; i++) {
    cin >> p[i] >> s[i];
    memo[p[i]].push_back(s[i]);
  }

  int ans = 0, pen = 0;

  for (int i = 1; i <= n; i++) {
    if (memo.count(i)) {
      int wa = 0;
      for (auto j = memo[i].begin(); j != memo[i].end(); j++) {
        if (*j == "AC") {
          ans++;
          pen += wa;
          break;
        }
        if (*j == "WA") {
          wa++;
        }
      }
    }
  }

  cout << ans << " " << pen << endl;
}