#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

// 深さ1上昇、増える文字数は1個以内(辞書順なので)
int n;
void dfs(int i, char c, string s) {
  if (i == n) {
    cout << s << '\n';
    return;
  }
  for (char nc = 'a'; nc <= c + 1; ++nc) dfs(i + 1, max(nc, c), s + nc);
}

int main() {
  cin >> n;
  dfs(0, 'a' - 1, "");
  return 0;
}