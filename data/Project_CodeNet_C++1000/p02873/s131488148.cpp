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
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size() + 1;

  vector<ll> cnt(n, 0);

  rep(i, n - 1) {
    if(s[i] == '<') {
      chmax(cnt[i + 1], cnt[i] + 1);
    }
  }

  per(i, n - 1) {
    if(s[i] == '>') {
      chmax(cnt[i], cnt[i + 1] + 1);
    }
  }

  ll ans = 0;
  rep(i, n) {
    ans += cnt[i];
  }

  cout << ans << endl;
}


// < > > > < < > < < < < < > > > <
// 0 3 2 1 0 1 2 0 1 2 3 4 5 2 1 0



// < < < < <
// 0 1 2 3 4

// > > > > >
// 4 3 2 1 0

// < < < > >
// 0 1 2 3 1
