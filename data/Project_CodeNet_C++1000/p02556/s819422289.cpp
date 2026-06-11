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
  ll n;
  cin >> n;
  vll z(n), w(n);
  rep(i,n) {
    ll x, y;
    cin >> x >> y;
    z[i] = x+y;
    w[i] = x-y;
  }
  ll zmax = -2000000000LL;
  ll zmin = 2000000000LL;
  ll wmax = -2000000000LL;
  ll wmin = 2000000000LL;
  rep(i,n) {
    zmax = max(zmax,z[i]);
    zmin = min(zmin,z[i]);
    wmax = max(wmax,w[i]);
    wmin = min(wmin,w[i]);
  }
  cout << max(zmax-zmin,wmax-wmin) << endl;
  return 0;
}