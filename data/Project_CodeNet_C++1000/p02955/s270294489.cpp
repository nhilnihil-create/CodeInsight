#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, k, s=0, ans=0;std::cin >> n >> k;
  vll a(n);re(i, n) std::cin >> a[i], s+=a[i];
  vll y;
  for(ll i=1;i*i<=s;i++) if(s%i==0) y.push_back(i), y.push_back(s/i);
  re(i, y.size()){
    ll t = 1000000000000000;
    vll x, z;
    re(j, n) x.push_back(a[j]%y[i]);
    re(j, n) z.push_back(y[i] - x[j]);
    sort(all(x));sort(all(z));
    rep(j, 1, n) x[j] += x[j-1], z[j] += z[j-1];
    re(j, n-1){
      t = min(t, max(x[j], z[n-2-j]));
    }
    t = min({t, x[n-1], z[n-1]});
    if(t<=k) ans = max(y[i], ans);
  }
  std::cout << ans << '\n';
  return 0;
}
