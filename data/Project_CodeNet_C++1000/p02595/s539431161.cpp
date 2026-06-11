#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll n, d;
  cin >> n >> d;
  d *= d;
  ll ans = 0LL;
  rep(i,n) {
    ll x, y;
    cin >> x >> y;
    if(x*x+y*y<=d) ans++;
  }
  cout << ans << endl;
  return 0;
}