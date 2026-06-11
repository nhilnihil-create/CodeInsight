#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int, int>;

/*
 */

signed main(){
  string s, t;
  cin >> s >> t;

  cout << t << s << endl;

  return 0;
}
