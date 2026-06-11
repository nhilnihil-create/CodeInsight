#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n, k, q;
  cin >> n >> k >> q;
  vector<ll> a(q);
  vector<ll> p(n, k);
  rep(i, q) {
    ll x;
    cin >> x;
    p[x-1]++;
  }
  rep(i, n) {
    string ans = (p[i] - q) > 0 ? "Yes" : "No";
    cout << ans << endl;
  }
  return 0;
}