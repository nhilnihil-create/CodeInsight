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
  lint N;
  cin >> N;
  vector<lint> P(N);
  REP(i, N) cin >> P[i];
  vector<lint> idx(N);
  REP(i, N) idx[P[i]-1] = i;
  multiset<lint> st;
  st.insert(-1);
  st.insert(-1);
  st.insert(N);
  st.insert(N);
  lint ans = 0;
  IREP(i, N) {
    st.insert(idx[i]);
    auto itr = st.find(idx[i]);
    lint l2 = *prev(itr, 2);
    lint l1 = *prev(itr, 1);
    lint r1 = *next(itr, 1);
    lint r2 = *next(itr, 2);
    //cout << l2 << " " << l1 << " " << idx[i] << " " << r1 << " " << r2 << endl;
    ans += ((l1-l2) * (r1-idx[i]) + (r2-r1) * (idx[i]-l1)) * (i+1);
  }
  cout << ans << endl;
}