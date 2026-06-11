#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  sort(h.rbegin(),h.rend());
  ll ans = 0;
  for(int i=k; i<=n-1; i++) ans += h[i];
  cout << ans << endl;
}
