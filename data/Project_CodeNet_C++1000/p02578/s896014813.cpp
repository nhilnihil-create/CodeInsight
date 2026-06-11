#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(a,b) for(ll i=a;i<b;i++)
#define endl "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  ll a[n];
  ll max = 0;
  FOR(0, n)
  {
    cin >> a[i];
  }
  ll ans = 0;
  FOR(1, n)
  {
    if (a[i - 1] > a[i]) {
      ans += a[i - 1] - a[i];
      a[i] = a[i - 1];
    }
  }
  cout << ans;
  return 0;
}

