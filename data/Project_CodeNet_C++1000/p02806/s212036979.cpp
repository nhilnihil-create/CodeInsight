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
  ll n;std::cin >> n;
  vector<pair<string, ll>> v(n);

  re(i, n) std::cin >> v[i].first >> v[i].second;
  string s;std::cin >> s;
  re(i, n){
    if(v[i].first==s){
      ll ans = 0;
      for(int j=i+1;j<n;j++) ans+=v[j].second;
      std::cout << ans << '\n';
      return 0;
    }
  }
  return 0;
}
