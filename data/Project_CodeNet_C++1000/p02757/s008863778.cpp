#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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
  lint N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  lint ans = 0;
  if(P == 2) {
    REP(i, N) {
      if(S[i] == '0' || S[i] == '2' || S[i] == '4' || S[i] == '6' || S[i] == '8') ans += i+1;
    }
  } else if(P == 5) {
    REP(i, N) {
      if(S[i] == '0' || S[i] == '5') ans += i+1;
    }
  } else {
    vector<lint> cnt(P);
    cnt[0] += 1;
    lint now = 0;
    lint base = 1;
    IREP(i, N) {
      now = (now + (S[i]-'0')*base)%P;
      cnt[now]++;
      base = base * 10 % P;
    }
    REP(i, P) {
      ans += cnt[i]*(cnt[i]-1)/2;
    }
  }
  cout << ans << endl;
}