#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  string S;
  cin>>S;
  int dp[S.size()+1][2];
  dp[0][0]=0;
  dp[0][1]=1;
  rep(i,S.size()){
    dp[i+1][0]=min(dp[i][0]+(S[i]-'0'),dp[i][1]+10-(S[i]-'0'));
    dp[i+1][1]=min(dp[i][0]+(S[i]-'0')+1,dp[i][1]+9-(S[i]-'0'));
  }
  cout<<dp[S.size()][0]<<endl;
}

