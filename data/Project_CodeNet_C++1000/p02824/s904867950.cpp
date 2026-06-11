#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A), greater<lint>());
  vector<lint> S(N+1);
  REP(i, N) S[i+1] = S[i] + A[i];
  int l = -1;
  int r = N;
  while(r-l > 1) {
    lint m = (l+r) / 2;
    if(A[P-1] > A[m]+M) {
      r = m;
      continue;
    }
    lint area = 0;
    REP(i, N) {
      if(i < P-1 || i >= m) {
        area += M;
      } else {
        area += A[m]+M-A[i];
      } 
    }
    if(area >= M*V) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l+1 << endl;
}