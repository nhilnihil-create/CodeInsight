#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/
signed main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  if(n == 1) {
    ll ans = k / 2;
    cout << ans << endl;
    return 0;
  }


  if(s[0] != s[n-1]) {
    ll dup = 0;
    ll tmp_dup = 1;
    REP(i,n-1) {
      if(s[i] == s[i+1]) {
        ++tmp_dup;
      } else {
        dup += tmp_dup / 2;
        tmp_dup = 1;
      }
    }
    dup += tmp_dup / 2;
    cout << dup*k << endl;
    return 0;
  }

  ll left_dup = 1;
  REP(i,n-1) {
    if(s[i] != s[i+1]) break;
    ++left_dup;
  }
  if(left_dup == n) {
    cout << n*k/2 << endl;
    return 0;
  }
  ll right_dup = 1;
  REPRS(i, 1, n-1) {
    if(s[i] != s[i-1]) break;
    ++right_dup;
  }

  ll half_cent_dup = 0;
  ll tmp_dup = 1;
  REPS(i,left_dup,n-right_dup) {
    if(s[i] == s[i+1]) {
      ++tmp_dup;
    } else {
      half_cent_dup += tmp_dup / 2;
      tmp_dup = 1;
    }
  }
  half_cent_dup += tmp_dup / 2;

  ll ans = 0;
  ll half_left_dup = left_dup / 2;
  ll half_right_dup = right_dup / 2;
  
  ans += half_cent_dup * k;
  ans += (k-1) * ((left_dup+right_dup)/2) + half_left_dup + half_right_dup;
  // LOG(half_left_dup);
  // LOG(half_cent_dup);
  // LOG(half_right_dup);
  cout << ans;
  cout << "\n";
  return 0;
}
/***** MAIN *****/
