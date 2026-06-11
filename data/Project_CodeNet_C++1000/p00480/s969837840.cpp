#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

int main()
{
  int n; cin >> n;
  int v[n]; FOR(i,0,n) cin >> v[i];
  ll dp[n][21]; CLR(dp);
  dp[1][v[0]] = 1;
  FOR(i,1,n-1) {
    FOR(j,0,21) {
      //if(dp[i][j] == 0) continue;
      if(j+v[i] <= 20) dp[i+1][j+v[i]] += dp[i][j];
      if(j-v[i] >= 0) dp[i+1][j-v[i]] += dp[i][j];
    }
  }
  cout << dp[n-1][v[n-1]] << endl;
  return 0;
}