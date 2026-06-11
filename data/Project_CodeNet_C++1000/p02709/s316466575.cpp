#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const int maxn = 2e3 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  int n; cin >> n;
  vector<pair<int,int> > a(n + 1);
  a[0] = mp(mod, 0);
  for (int i = 1; i <= n; ++i){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(All(a), greater<pair<int,int> >());
  vector<vector<ll> > f(n+1, vector<ll>(n+1, 0));
  ll ans = 0;
  for (int i = 0; i <= n; ++i) for (int j = 0; i + j <= n; ++j){
    if (i + j == n) ans = max(ans, f[i][j]);
    else {
      f[i][j+1] = max(f[i][j+1], f[i][j] + 1ll * abs(n - j - a[i+j+1].second) * a[i+j+1].first);
      f[i+1][j] = max(f[i+1][j], f[i][j] + 1ll * abs(a[i+j+1].second - (i+1) ) * a[i+j+1].first);
    }
  }
  cout << ans;
}


