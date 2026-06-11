#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

int dp[1000100][2];

int main(){
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  s += '0';
  int n = s.size();
  fill((int*)dp, (int*)dp + sizeof(dp) / sizeof(int), INF);
  dp[0][0] = 0;
  for(int i = 0; i < n; ++i){
  	for(int j = 0; j < 2; ++j){
  		int d = s[i] - '0';
  		d += j;
  		if(d <= 9)dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + d);
  		if(d)dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 10 - d);
  	}
  }

  cout << dp[n][0] << endl;
  return 0;
}
