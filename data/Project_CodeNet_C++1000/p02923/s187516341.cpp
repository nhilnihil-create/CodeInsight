#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N) cin >> H[i];
  int ans = 0;
  int tmp = 0;
  REP(i, N - 1) {
    if (H[i] >= H[i + 1]) {
      tmp++;
    } else {
      tmp = 0;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}