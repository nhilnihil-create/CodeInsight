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
typedef __int128_t lll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll k, q;std::cin >> k >> q;
  vll d(k); re(i, k) scanf("%lld", &d[i]);


  re(i, q){
    ll n, x, m;scanf("%lld %lld %lld", &n, &x, &m);
    x%=m;
    ll c = 0, now = 0;

    re(j, k) {
      ll tmp = d[j]%m;
      if(now >= (now+tmp)%m) c++;
      now = (now + tmp)%m;
    }

    c = c * ((n-1)/k);
    c += (now*((n-1)/k))/m;
    now = (now*((n-1)/k))%m;
    if(now+x>=m) c++;
    now = (now+x)%m;

    for(ll j=0;j<((n-1)%k);j++){
      ll tmp = d[j]%m;
      if(now >= (now+tmp)%m) c++;
      now = (now + tmp)%m;
    }
    std::cout << n - 1 - c << '\n';
  }
  return 0;
}
