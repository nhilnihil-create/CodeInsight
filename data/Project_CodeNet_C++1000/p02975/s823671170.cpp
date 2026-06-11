#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef long long ll;

/* --- INFやMODの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

bool f1(vector<int> a) {
  rep(i, a.size()) {
    if (a[i] > 0) return false;
  }
  return true;
}

bool f2(vector<int> a) {
  int n = a.size();

  if (n % 3) return false;

  REP(i, 0, n / 3) {
    if (a[i] != 0) return false;
  }

  REP(i, n / 3, n) {
    if (a[n / 3] != a[i]) return false;
  }

  return true;
}

bool f3(vector<int> a) {
  int n = a.size();

  if (n % 3) return false;

  REP(i, 0, n / 3) {
    if (a[0] != a[i]) return false;
  }

  REP(i, n / 3, n / 3 * 2) {
    if (a[n / 3] != a[i]) return false;
  }

  REP(i, n / 3 * 2, n) {
    if (a[n / 3 * 2] != a[i]) return false;
  }

  return (a[0] ^ a[n / 3] ^ a[n / 3 * 2]) == 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  cout << ((f1(a) || f2(a) || f3(a)) ? "Yes" : "No") << endl;
}
