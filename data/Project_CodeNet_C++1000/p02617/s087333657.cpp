#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  // L ~ R
  //(R - L + 1) - (両端とも集合に含まれる辺)
  ll S = 0;
  for(ll i=1;i<=n;i++) S += i*(n-i+1);
  //S - ∑{e}(辺eがカウントされる回数)

  ll cnt = 0;
  for(int i=0;i<n-1;i++){
    ll a, b;std::cin >> a >> b;
    if(a>b) swap(a, b);
    cnt += (a*(n-b+1));
  }
  //std::cout << cnt << '\n';

  std::cout << S - cnt << '\n';
  return 0;
}
