//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll d;
  cin >> n >> d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ans += (x * x + y * y <= d * d);
  }
  cout << ans << '\n';
  return 0;
}
