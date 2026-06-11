#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string s1, s2;

int lcs() {
  int i, j;
  int dp[s1.length()+1][s2.length()+1] = {};
  
  for(i = 1; i <= s1.length(); i++) {
    for(j = 1; j <= s2.length(); j++) {
      if(s1[i-1] == s2[j-1])
	dp[i][j] = dp[i-1][j-1]+1;
      else
	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  
  }
  return dp[s1.length()][s2.length()];
}

int main(){
  int n;
  cin >> n;
  while(n--) {
    cin >> s1 >> s2;
    cout << lcs() << endl;
  }
  
  return 0;
}