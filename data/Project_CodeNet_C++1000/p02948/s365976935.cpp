#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> Q(100100);
  REP(i, N) {
    int A, B;
    cin >> A >> B;
    Q[A].push_back(B);
  }
  int ans = 0;
  priority_queue<int> pq;
  for(int i = 1; i <= M; i++) {
    REP(j, Q[i].size()) {
      pq.push(Q[i][j]);
    }
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    
  }
  cout << ans << endl;
  return 0;
}