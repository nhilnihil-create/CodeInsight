#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n; cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  sort(d.begin(),d.end());
  int ans = d[d.size()/2]-d[d.size()/2-1];
  cout << ans << endl;
  return 0;
}