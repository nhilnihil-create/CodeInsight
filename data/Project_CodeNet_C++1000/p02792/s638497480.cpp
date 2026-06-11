#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<vector<int> > cnt(10, vector<int>(10));
  for (int i = 1; i <= n; ++i) {
    string s = to_string(i);
    int l = s.size();
    cnt[s[0] - '0'][s[l - 1] - '0']++;
  }
  int ans = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      ans += cnt[i][j] * cnt[j][i];
    }
  }
  cout << ans << endl;
  return 0;
}