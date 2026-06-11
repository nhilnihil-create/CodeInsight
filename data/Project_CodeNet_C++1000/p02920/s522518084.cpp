#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<int> s(1 << n);
  rep(i, 1 << n) cin >> s[i];

  sort(s.begin(), s.end());
  multiset<int> t;
  rep(i, (1 << n) - 1) t.insert(s[i]);
  vector<int> res;
  res.push_back(s[(1 << n) - 1]);
  rep(i, n) {
    vector<int> nxt = res;
    rep(j, res.size()) {
      auto it = t.lower_bound(res[j]);
      if (it == t.begin()) {
        cout << "No" << endl;
        return 0;
      }
      it--;
      nxt.push_back(*it);
      t.erase(it);
    }
    sort(nxt.begin(), nxt.end(), greater<int>());
    swap(res, nxt);
  }
  cout << "Yes" << endl;
  
  


  
  return 0;
}