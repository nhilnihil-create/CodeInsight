#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<int, int>> ans;
  if (N % 2 == 1) {
    for (int l = 1, r = N - 1; l < r; l++, r--) {
      ans.emplace_back(l, r);
    }
  } else {
    bool flag = false;
    for (int l = 1, r = N - 1; l < r; l++, r--) {
      if (!flag && r - l <= N / 2) {
        --r;
        flag = true;
      }
      ans.emplace_back(l, r);
    }
  }
  for (int i = 0; i < M; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}