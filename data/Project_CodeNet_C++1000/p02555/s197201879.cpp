#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;

ll dp[2010]={};

int main() {
  int n;
  cin >> n;
  dp[0]=1;
  rep(i,n+1){
    for(int j=i+3;j<=n;j++){
      dp[j]+=dp[i];
      dp[j]%=mod;
    }
  }
  cout << dp[n] << endl;
}