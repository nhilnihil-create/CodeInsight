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
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, a;std::cin >> n;
  std::vector<ll> num(300001, 0), S(300001, 0), T(300001, 0);
  for(int i=0;i<n;i++){
    std::cin >> a;
    num[a]++;
  }
  for(int i=1;i<=n;i++) S[num[i]]++;
  std::vector<ll> x(n, 0);

  S[0] = T[0] = 0;
  for(int i=1;i<=n;i++) {
    T[i] = T[i-1] + S[i];
    S[i] = S[i-1] + S[i] * i;
  }
  for(int i=1;i<=n;i++) x[i-1] = (S[i] + i * (T[n]-T[i]))/i;
  sort(x.begin(), x.end());
  //std::cout << x[0] << " "  << x[1] << " " << x[2] << '\n';
  for(int i=1;i<=n;i++){
    ll ans = lower_bound(x.begin(), x.end(), i) - x.begin();
    std::cout << n - ans << '\n';
  }

  return 0;
}
