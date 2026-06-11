#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  rep(i, 0, n * 2) {
    if (i % 2 == 0)
      cout << s[i / 2];
    else
      cout << t[(i - 1) / 2];
  }
  cout << endl;
  return 0;
}