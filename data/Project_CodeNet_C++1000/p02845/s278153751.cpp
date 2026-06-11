#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int MOD = pow(10, 9) + 7;
int main() {
  int N; cin >> N;
  vector<int> last(3, -1);
  long long ans = 1;
  REP(i, N) {
    int A; cin >> A;
    int cnt = 0;
    REP(j, 3) {
      if (last[j] + 1 == A) cnt++;
    }
    REP(j, 3) {
      if (last[j] + 1 == A) {
        last[j] = A;
        break;
      }
    }
    ans = (ans * cnt) % MOD;
  }
  cout << ans << endl;
  return 0;
}