#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
using P = pair<int, int>;

#define LOG(variable) cerr << #variable":\t" << (variable) << "\n"
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cerr << (i) << ":\t" << (container)[(i)] << "\n"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, n, r) for(int i = (n); i >= (r); --i) // from n to r
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
template<typename T = int>
T in() {T a; cin >> a; return a;}
/***** MAIN *****/
signed main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a_cum_sum(n+1, 0LL), b_cum_sum(m+1, 0LL);
  for(int i = 0; i < n; ++i) {
    int a; cin >> a;
    a_cum_sum[i+1] = a_cum_sum[i] + a;
  }
  for(int i = 0; i < m; ++i) {
    int b; cin >> b;
    b_cum_sum[i+1] = b_cum_sum[i] + b;
  }
  int ans = 0;
  for(int i = 0; i < n+1; ++i) {
    if(a_cum_sum[i] > k) break;
    int rest = k - a_cum_sum[i];
    int index = upper_bound(ALL(b_cum_sum), rest) - b_cum_sum.begin();
    // index:5のとき、index:4までrestをこしてないっていうことになるので[0,4)の範囲で本を読める。→0,1,2,3の4冊→index-1が答え
    ans = max(ans, i+index-1);
  }
  cout << ans;

  cout << "\n";
  return 0;
}
/***** MAIN *****/