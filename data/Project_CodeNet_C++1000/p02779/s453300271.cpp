#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll x;
    cin >> x;
    if (mp.find(x) != mp.end()) {
      cout << "NO" << endl;
      return 0;
    }
    mp[x] = 1;
  }
  cout << "YES" << endl;
  return 0;
}