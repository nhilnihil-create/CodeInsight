#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<long long> plus, minus;
  rep(i, N) {
    ll a; cin >> a;
    if (a >= 0) plus.push_back(a);
    else minus.push_back(a);
  }

  sort(plus.begin(), plus.end(), greater<long long>());
  sort(minus.begin(), minus.end());
  if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
  if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();

  vector<pair<long long, long long> > res;
  long long cur = minus[0];
  for (int i = 0; i+1 < plus.size(); ++i) {
      res.push_back({cur, plus[i]});
      cur -= plus[i];
  }
  res.push_back({plus.back(), cur});
  cur = plus.back() - cur;

  for (int i = 1; i < minus.size(); ++i) {
      res.push_back({cur, minus[i]});
      cur -= minus[i];
  }

  cout << cur << endl;
  for (auto p : res) cout << p.first << " " << p.second << endl;
}
