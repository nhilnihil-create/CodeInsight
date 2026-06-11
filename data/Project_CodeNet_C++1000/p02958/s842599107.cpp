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
  cin >> n;
  vector<int> p(n);
  rep(i, 0, n) { cin >> p[i]; }
  vector<int> pp = p;
  sort(all(p));
  int ans = 0;
  rep(i,0,n){
    if (p[i] != pp[i]) ans++;
  }
  if (ans <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}