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

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> v(M + 1);
  for (int i = 0; i < N; ++i) {
    int A, B; cin >> A >> B;
    if (A > M) continue;
    v[A].push_back(B);
  }

  LL total = 0;
  priority_queue<LL> que;
  for (int i = M-1; i >= 0; --i) {
    for (int x : v[M-i]) que.push(x);
    if (!que.empty()) {
      total += que.top(); que.pop();
    }
  }
  cout << total << endl;
}
