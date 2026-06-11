#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(string x){
  set<char> num;
  for(int i=0;i<(int)x.size();i++){
    num.insert(x[i]);
  }
  return num.size();
}

int main(){
  int N;
  cin >> N;
  vector<vector<string>> dp(10);
  dp[0].push_back("a");
  for(int i=1;i<=9;i++){
    for(auto x : dp[i-1]){
      for(int j=0;j<min(26,f(x))+1;j++){
        dp[i].push_back(x+(char)(j+'a'));
      }
    }
  }
  --N;
  for(int i=0;i<(int)dp[N].size();i++){
    cout << dp[N][i] << endl;
  }
}