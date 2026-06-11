# include <bits/stdc++.h>
using namespace std;

int health, n, dmg[1005], cost[1005];
int dp[10005][1005];

int solve(int health, int pos){
  if(health <= 0) return 0;
  if(pos >= n) return 1e9;

  int &res = dp[health][pos];
  if(res != -1) return res;
  res = INT_MAX;
  res = min(res, solve(health, pos+1));
  res = min(res, solve(health-dmg[pos], pos) + cost[pos]);
  return res;
}

int main(){

  ios_base :: sync_with_stdio(false);

  cin >> health >> n;
  for(int i=0; i<n; i++) cin >> dmg[i] >> cost[i];
  memset(dp, -1, sizeof(dp));

  cout << solve(health, 0) << endl;
  return 0;
}