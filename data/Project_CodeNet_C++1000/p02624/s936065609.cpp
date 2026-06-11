#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(ll i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  ll ans = 0;
  vector<int> vec(n+1, 0);
  reps(i, 1, n+1) {
    for(ll j = i; j <= n; j += i) {
      vec.at(j)++;
    }
  }
  reps(i, 1, n+1) {
    ans += i * vec.at(i);
  }
  cout << ans << endl;
  return 0;
}