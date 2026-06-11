#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  priority_queue<int, vector<int>> pq;
  REP(i, N) {
    int a;
    cin >> a;
    pq.push(a);
  }
  REP(i, M) {
    int a = pq.top();
    pq.pop();
    pq.push(a / 2);
  }
  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
}