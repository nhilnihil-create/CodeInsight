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
  lint N, K;
  cin >> N >> K;
  vector<lint> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
  }
  vector<lint> S(N+1);
  FOR(i, 1, N+1) S[i] = A[i-1] + S[i-1];
  map<lint, lint> cnt;
  REP(i, min(N+1, K)) {
    cnt[S[i]%K]++;
  }
  lint ans = 0;
  int j = K;
  REP(i, N+1) {
    cnt[S[i]%K]--;
    ans += cnt[S[i]%K];
    if(j < N+1) {
      cnt[S[j]%K]++;
      j++;
    }
  }
  cout << ans << endl;
}