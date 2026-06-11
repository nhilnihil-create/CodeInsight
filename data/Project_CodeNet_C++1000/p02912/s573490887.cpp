#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  priority_queue<int> que;
  int N, M;
  cin >> N >> M;
  REP(i, N) {
    int l;
    cin >> l;
    que.push(l);
  }
  while(M>0){
    M--;
    int tmp = que.top();
    que.pop();
    que.push(tmp / 2);
  }
  ll ans = 0;
  while(!que.empty()){
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
}