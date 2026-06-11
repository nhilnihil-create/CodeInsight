#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1000000007;
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

vector<int> z_algorhythm(const string &S) {
  const int N = S.size();
  vector<int> res(N);
  res[0] = N;

  int i = 1, j = 0;
  while (i < N) {
    while (i + j < N && S[j] == S[i + j]) ++j; // j = 開始位置 i から何文字等しいか
    res[i] = j;
    if (j == 0) {++i; continue;} // 何文字も等しくなければ continue

    int k = 1;
    while (i + k < N && k + res[k] < j) {
      res[i + k] = res[k];
      ++k;
    }
    i += k, j -= k;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;

  rep(i, n) {
    string str = s.substr(i);
    int strn = str.size();
    auto lcp = z_algorhythm(str);

    rep(j, strn) {
      chmax(ans, min(lcp[j], j));
    }
  }

  cout << ans << endl;
}
