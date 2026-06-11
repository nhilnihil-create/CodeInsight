#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, L;
  cin >> N >> L;
  vector<int> A(0);
  for (int i = 1; i <= N; i++) {
    A.push_back(L + i - 1);
  }
  sort(A.begin(), A.end());
  int id = 0, num = abs(A[0]);
  REP(i, A.size()) {
    if (abs(A[i]) < abs(num)) {
      id = i;
      num = A[i];
    }
  }
  int ans = 0;
  REP(i, N) {
    if (i == id) continue;
    ans += A[i];
  }
  cout << ans << endl;
}