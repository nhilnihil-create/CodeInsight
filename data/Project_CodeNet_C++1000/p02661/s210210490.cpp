#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

int countup(vector<pair<int,int>> &AB, int a, int b) {
  int upper = a-1;
  int cnt = 0;
  for (auto p:AB) {
    if (p.second < a || p.first > b) {
      continue;
    }

    if (upper >= min(p.second, b)) {
      continue;
    }

    cnt += min(p.second, b) - max(p.first-1, upper);
    upper = min(p.second, b);
  }

  return cnt;
}

void solve() {
  int N;
  cin >> N;

  vector<int> A, B;
  vector<pair<int,int>> AB;

  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
    AB.emplace_back(a, b);
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(AB.begin(), AB.end());

  int ap, bp;
  if (N % 2 == 1) {
    ap = A[N/2];
    bp = B[N/2];
    cout << bp-ap+1 << endl;
    return;
  }


  int ans = 0;
  ap = A[N/2-1] + A[N/2];
  bp = B[N/2-1] + B[N/2];
  cout << (bp-ap)+1 << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
