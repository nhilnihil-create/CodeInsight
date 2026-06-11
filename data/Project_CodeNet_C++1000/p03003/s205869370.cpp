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
  ll P=1000000007,n, m;std::cin >> n >> m;
  vll a(n), b(m);re(i, n) std::cin >> a[i]; re(i, m) std::cin >> b[i];
  vvl dp = vv(n+1, m+1, 0, ll);

  vll s(m+1, 0), t(m+1, 0);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]!=b[j-1]) continue;
      dp[i][j] = (s[j-1] + 1)%P;
    }
    for(int j=0;j<=m;j++) t[j] = (t[j] + dp[i][j])%P;
    for(int j=1;j<=m;j++) s[j] = (s[j-1] + t[j])%P;
  }
  ll ans = 0;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans = (ans+dp[i][j])%P;
  std::cout << (ans+1)%P << '\n';
  return 0;
}
