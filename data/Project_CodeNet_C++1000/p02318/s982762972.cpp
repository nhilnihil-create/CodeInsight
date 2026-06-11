#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
  dp[0][0] = 0;
  rep(i, s1.size()) dp[i+1][0] = i+1;
  rep(i, s2.size()) dp[0][i+1] = i+1;
  rep(i, s1.size()) rep(j, s2.size()) {
    dp[i+1][j+1] = min({dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+(s1[i]==s2[j] ? 0 : 1)});
  }
  cout << dp[s1.size()][s2.size()] << endl;
  return 0;
}
