#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;
lint p=1e9+7;

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> S(N),T(M);
  REP(i,N)cin>>S[i];
  REP(i,M)cin>>T[i];
  vector<vector<lint> > dp(N+1,vector<lint>(M+1,0)),s(N+1,vector<lint>(M+1,0));
  FOR(i,1,N+1)FOR(j,1,M+1){
    if(S[i-1]==T[j-1])dp[i][j]=s[i-1][j-1]+1;
    dp[i][j]%=p;
    s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+dp[i][j];
    s[i][j]+=p;
    s[i][j]%=p;
  }
  cout<<s[N][M]+1<<endl;
  return 0;
}
