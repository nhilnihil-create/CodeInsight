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
  int N;
  cin >> N;
  multiset<lint, greater<lint>> st;
  REP(i, 1LL<<N) {
    lint A;
    cin >> A;
    st.insert(A);
  }
  vector<lint> vec;
  vec.push_back(*st.begin());
  st.erase(st.begin());
  REP(k, N) {
    REP(i, 1LL<<k) {
      auto itr = st.upper_bound(vec[i]);
      if(itr == st.end()) {
        cout << "No" << endl;
        return 0;
      }
      vec.push_back(*itr);
      st.erase(itr);
     }
  }
  cout << "Yes" << endl;
}