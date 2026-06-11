#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N;
  cin >> N;
  vector<lint> cnt(N);
  REP(i, N) {
    lint A;
    cin >> A;
    cnt[A-1]++;
  }
  sort(ALL(cnt));
  vector<lint> Scnt(N+1);
  REP(i, N) Scnt[i+1] = Scnt[i] + cnt[i];
  vector<lint> ans(N);
  lint pool = 0;
  REP(i, N) {
    lint l = -1;
    lint r = N*N + 1;
    while(r-l > 1) {
      lint m = (l+r) / 2;
      lint ll = -1;
      lint rr = N;
      while(rr-ll > 1) {
        lint mm = (ll+rr) / 2;
        if(cnt[mm] <= m) ll = mm;
        else rr = mm;
      }
      if(ll >= i && Scnt[ll+1] - Scnt[i] + pool < m * (ll + 1 - i)) r = m;
      else l = m;
    }
    ans[N-1-i] = l;
    pool += cnt[i];
  }
  REP(i, N) cout << ans[i] << "\n";
}