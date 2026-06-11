#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;

 
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vec<int> c(n);
  int a[n][m];
  rep(i, n){
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  int ans = INF;
  for (int tmp = 0; tmp < (1 << 12); tmp++){ 
    bitset<12> s(tmp);
    vec<int> comp(m, 0);
    int money = 0;
    rep(i, n){
      if(s.test(i)){
        money += c[i];
        rep(j, m) comp[j] += a[i][j];
      }
    }
    bool ok = true;
    rep(i, m){
      if(comp[i] < x) ok = false;
    }
    if(ok) ans = min(ans, money);
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}