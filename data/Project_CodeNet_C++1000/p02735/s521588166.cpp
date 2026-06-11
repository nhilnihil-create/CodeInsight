#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int H, W;
int INF = 100000000;
int main(){
  cin >> H >> W;
  char maze[H][W];
  int dp[H][W];
  rep(i, H)rep(j, W) cin >> maze[i][j];
  rep(i, H)rep(j, W) dp[i][j] = INF;
  rep(i, H)rep(j, W){
    if (i == 0 && j == 0){
      if (maze[i][j] == '#') dp[0][0] = 1;
      else dp[0][0] = 0;}
    else if (i == 0){
      if (maze[i][j-1] == '.' && maze[i][j] == '#')dp[i][j] = dp[i][j-1]+1;
      else dp[i][j] = dp[i][j-1];
    }
    else if (j == 0){
      if (maze[i-1][j] == '.'  && maze[i][j] == '#')dp[i][j] = dp[i-1][j] + 1;
      else dp[i][j] = dp[i-1][j];
    }
    else{
      int a, b;
      if (maze[i][j-1] == '.' && maze[i][j] == '#')a = 1;
      else a = 0;
      if (maze[i-1][j] == '.' && maze[i][j] == '#')b = 1;
      else b = 0;
      dp[i][j] = min(dp[i][j-1] + a, dp[i-1][j] + b);
    }
  }
  cout << dp[H-1][W-1] << endl;
}  