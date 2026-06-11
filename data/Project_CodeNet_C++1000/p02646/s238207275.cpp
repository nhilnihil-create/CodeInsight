#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll a, v, b, w, t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;
  bool ok = true;
  if (abs(a-b) > (v-w)*t) ok = false;
  cout << (ok?"YES\n":"NO\n");
}