#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
#define RFOR(i, k, j) for (int i = k - 1; i >= j; i--)
#define RREP(i, j) RFOR(i, j, 0)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec)
    is >> x;
  return is;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  int n;
  cin >> n;

  REP(i, n - 1) {
    FOR(j, i + 1, n) {
      int x = abs(i - j);
      REP(k, 10) if (x & (1 << k)) {cout << k + 1 << " "; break;}
    }
    cout << endl;
  }

  return 0;
}
