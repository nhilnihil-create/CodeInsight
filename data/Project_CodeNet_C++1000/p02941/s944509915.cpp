// compile option: g++ -std=c++11
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<int, int> P;
typedef vector<P> VP;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  priority_queue<P> que;
  REP(i, n) que.push(P(b[i], i));
  ll ans = 0;
  while (que.size()) {
    P p = que.top();
    que.pop();
    int i = p.second;
    int sum = b[(i - 1 + n) % n] + b[(i + 1) % n];
    if (sum < b[i]) {
      int t = (b[i] - a[i]) / sum;
      if (0 < t) {
        b[i] -= t * sum;
        que.push(P(b[i], i));
        ans += t;
      }
    }
  }
  REP(i, n) {
    if (a[i] != b[i]) ans = -1;
  }
  cout << ans << endl;
  return 0;
}