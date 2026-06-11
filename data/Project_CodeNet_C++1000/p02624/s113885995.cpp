#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  vector<ll> vec(n+1, 0);
  ll ans = 0;
  for(ll i = 1; i <= n; i++) {
    for(ll j = i; j <= n; j += i) {
      vec.at(j)++;
    }
  }
  
  for(ll i = 1; i <= n; i++) {
    ans += i * vec.at(i);
  }
  cout << ans << endl;
  return 0;
}