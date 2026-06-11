#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
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
using P = pair<int, int>;
int in() {int x; cin>>x; return x;}
string stin() {string s; cin>>s; return s;}
/***** MAIN *****/
signed main() {
  int n = in();
  vector<P> v(n);
  REP(i,n) {
    int first = in(), second = in();
    v[i] = P(first, second);
  }
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  map<P, int> vector_mp;
  REP(i,n) {
    REP(j,n) {
      if(i == j) continue;
      int first_diff = v[j].first - v[i].first;
      int second_diff = v[j].second - v[i].second;
      ++vector_mp[P(first_diff, second_diff)];
    }
  }
  int most_occur = 0;
  for(auto& itr : vector_mp) {
    most_occur = max(most_occur, itr.second);
  }
  cout << n - most_occur;
  cout << "\n";
  return 0;
}
/***** MAIN *****/
