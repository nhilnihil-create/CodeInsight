#include <iostream>
#include <string>
#include <vector>
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
  ll n, m, INF = 100000000000000000;std::cin >> n >> m;
  vvl d = VV(m, 3, 0, ll);
  re(i, m){
    scanf("%lld %lld", &d[i][0], &d[i][1]);
    ll tmp = 0;
    re(j, d[i][1]){
      ll c;scanf("%lld", &c);
      tmp += 1<<(c-1);
    }
    d[i][2] = tmp;
  }
  vvl dp = VV(m+1, 1<<n, INF, ll);
  dp[0][0] = 0;

  for(int i=0;i<m;i++){
    for(int j=0;j<(1<<n);j++){
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      dp[i+1][j|d[i][2]] = min(dp[i+1][j|d[i][2]], dp[i][j]+d[i][0]);
    }
  }
  std::cout << (dp[m][(1<<n)-1]==INF?-1:dp[m][(1<<n)-1]) << '\n';
  return 0;
}
