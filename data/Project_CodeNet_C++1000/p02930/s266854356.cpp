#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vi> ans(n, vi(n, 0));

  int cnt = 0;
  int tmp = n;
  while (tmp) {
    cnt++;
    tmp /= 2;
  }

  REP(i, cnt) {
    REP(j, n) {
      if ((j >> i) % 2 == 1) {
        REP(k, n) {
          if ((k >> i) % 2 == 0) {
            ans[j][k] = i + 1;
            ans[k][j] = i + 1;
          }
        }
      }
    }
  }

  REP(i, n - 1) {
    FOR(j, i + 1, n) { cout << ans[i][j] << (j == n - 1 ? "\n" : " "); }
  }

  return 0;
}
