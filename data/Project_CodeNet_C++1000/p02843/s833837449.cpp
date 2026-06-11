#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstring>
 
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;
 
bool dp[100005];
 
int main() {
  memset(dp, false, sizeof dp);
 
  int x;
  cin >> x;
 
  vi denom = {100, 101, 102, 103, 104, 105};
  dp[0] = true;
  dp[100] = dp[101] = dp[102] = dp[103] = dp[104] = dp[105] = true;
  for (int i = 106; i <= x; ++i) {
    for (int d : denom) {
      if (dp[i-d]) {
        dp[i] = true;
        break;
      }
    }
  }
 
  cout << dp[x] << endl;
  return 0;
}