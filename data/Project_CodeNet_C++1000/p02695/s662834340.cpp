#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int N, M, Q;
vector<int> a, b, c, d;

int dfs(vector<int> v, int last) {
  v.push_back(last);
  if (v.size() == N) {
    int score = 0;
    for (int i = 0; i < Q; ++i) {
      if (v[b[i]] - v[a[i]] == c[i]) score += d[i];
    }
    return score;
  }

  int score = 0;
  for (int i = last; i <= M; ++i) {
    score = max(score, dfs(v, i));
  }
  return score;
}

int main() {
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }

  int score = 0;
  for (int i = 1; i <= M; ++i) {
    score = max(score, dfs({}, i));
  }
  cout << score << endl;
}
