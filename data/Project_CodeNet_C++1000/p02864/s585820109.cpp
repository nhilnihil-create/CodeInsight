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
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
#define vvv vector<vector<vector<long long int>>>
#define vvvl(a, b, c, d) vector<vector<vector<long long int>>>(a, vector<vector<long long int>>(b, vector<long long int> (c, d)));
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, K;std::cin >> n >> K;
  std::vector<ll> h(n);
  map<ll, ll> mp;
  mp.emplace(0, 0);
  for(int i=0;i<n;i++){
    std::cin >> h[i];
    mp.emplace(h[i], 0);
  }
  ll c = 0;
  std::vector<ll> cost(mp.size());
  for(auto itr=mp.begin();itr!=mp.end();itr++, c++) {
    (*itr).second = c;
    cost[c] = (*itr).first;
  }
  for(int i=0;i<n;i++) h[i] = mp.at(h[i]);
  ll st = 0;
  for(int i=0;i<n;i++){
    if(i==0) st += cost[h[i]];
    else if(cost[h[i]]>cost[h[i-1]]) st+= cost[h[i]] - cost[h[i-1]];
  }

  vvv dp = vvvl(n+1, mp.size(), K+1, -100000000000000);
  dp[0][0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<mp.size();j++){
      for(int k=0;k<=K;k++){
        dp[i][h[i-1]][k] = max({dp[i][h[i-1]][k], dp[i-1][j][k]});
        if(k==0) continue;
        ll down = 0;
        if(cost[h[i-1]]>cost[j]) down += cost[h[i-1]] - cost[j];
        if(i!=n&&cost[h[i]]>cost[h[i-1]]) down += cost[h[i]] - cost[h[i-1]];
        if(i!=n&&cost[h[i]]>cost[j]) down -= cost[h[i]] - cost[j];
        down = max((ll)0, down);
        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + down);
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<mp.size();i++) ans = max(ans, dp[n][i][K]);
  std::cout << st - ans << '\n';
  return 0;
}
