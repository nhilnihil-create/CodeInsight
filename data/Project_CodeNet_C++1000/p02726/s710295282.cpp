// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

/*
            x                       y
0  -  1  -  2  -  3  -  4  -  5  -  6
            |                       |
            -  -  -  -  -  -  -  -  -

*/
int dp[2000][2000];
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--;y--;
  
  loop(i,0,n) loop(j,0,n) {
    dp[i][j] = abs(j-i);
  }
  loop(i,0,n) loop(j,0,n) {
    dp[j][i] = dp[i][j] = min(dp[j][i], dp[j][y] + dp[x][i] + 1);
    dp[j][i] = dp[i][j] = min(dp[j][i], dp[j][x] + dp[y][i] + 1);
  }
  
  vector<int> C(2100, 0);
  loop(i,0,n-1) loop(j,i+1,n) C[dp[i][j]]++;
  
  loop(k,1,n) cout << C[k] << endl;
  return 0;
}
