#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <climits>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;

const int MAXN = 200002;

int n;
string s;

int memo[MAXN][4];
int dp(int i, int l) {
  if (i+1 >= n) return 0;
  if (!memo[i][l]) {
    memo[i][l] = INT_MIN;
    for (int r = 1; r <= 3; ++r) {
      if (i+r >= n) break;
      if (s.substr(i-l+1, l) == s.substr(i+1, r)) continue;
      memo[i][l] = max(memo[i][l], dp(i+r, r) + 1);
    }
  }
  return memo[i][l];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = s.size();
  int ans = max(dp(0, 1), max(dp(1, 2), dp(2, 3))) + 1;
  cout << ans << "\n";
  return 0;
}