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
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  lint allxor = 0;
  REP(i, N) allxor ^= A[i];
  REP(i, N) REP(j, 60) if(allxor>>j&1 && A[i]>>j&1) A[i] -= 1LL<<j;
  set<lint, greater<lint>> st;
  REP(i, N) {
    for(lint x : st) A[i] = min(A[i], A[i]^x);
    if(A[i] > 0) st.insert(A[i]);
  }
  lint alland = 0;
  for(lint x : st) alland = max(alland, alland^x);
  cout << allxor + alland * 2 << endl;
}