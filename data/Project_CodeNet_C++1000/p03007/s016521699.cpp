#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main(int argc, char* argv[])
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  sort(ALL(a));

  ll a_min = a[0];
  ll a_max = a[n-1];

  vector<pair<ll, ll>> steps(n-1);

  for (int i = 1; i < n-1; i++) {
    if (a[i] > 0) {
      steps[i-1] = make_pair(a_min, a[i]);
      a_min -= a[i];
    } else {
      steps[i-1] = make_pair(a_max, a[i]);
      a_max -= a[i];
    }
  }
  steps[n-2] = make_pair(a_max, a_min);

  cout << a_max - a_min << endl;
  rep(i, n-1) {
    cout << steps[i].first << " " << steps[i].second << endl;
  }
  cout << endl;

  return 0;
}
