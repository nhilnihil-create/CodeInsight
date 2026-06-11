// ????????±?????¨??????
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#define MAX 1050
using namespace std;
int q,length_x,length_y;
int dp[MAX][MAX];
string X,Y;
int init_func () {
  for (int i=0; i<MAX ; i++)
    for (int j=0; j<MAX ; j++)
      dp[i][j] = 0;
}

int solve () {
  // dp = {0}
  // dp?????¨?????????X????¨????Y??¨??????
  for (int tate=1; tate<=length_x ; tate++)
    for (int yoko=1; yoko<=length_y ; yoko++)
      if (X[tate-1] == Y[yoko-1]) dp[tate][yoko] = 1 + dp[tate-1][yoko-1];
      else dp[tate][yoko] = max(dp[tate-1][yoko],dp[tate][yoko-1]);
  
  return dp[length_x][length_y];
}

int main(){
  cin >> q;
  for (int i=0; i<q; i++) {
    cin >> X >> Y;
    length_x = X.length();
    length_y = Y.length();
    init_func();
    cout << solve() << endl;
  }
  return 0;
}