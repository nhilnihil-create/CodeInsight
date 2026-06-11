#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(all(a));
  int ans = 0;
  for(int i = 0; i + 1 < n; i++) {
    for(int j = i + 1; j < n ; j++) {
      int l = lower_bound(all(a) , a[i] + a[j]) - a.begin();
      ans += l - j - 1;
    }
  }
  cout << ans << '\n';
}
