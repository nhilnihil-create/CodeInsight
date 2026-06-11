#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const int INF =  999999999;

int dp[1000005][2];

int main(){
  string s;
  cin>>s;
  reverse(s.begin(),s.end());
  s+='0';
  int n=s.length();
  rep(i,n+1)rep(j,2)dp[i][j]=INF;
  dp[0][0]=0;
  rep(i,n)rep(j,2){
    int y=s[i]-'0';
    y+=j;
    rep(a,10){
      int ni=i+1,nj=0;
      int b=a-y;
      if(b<0){
        b+=10;
        nj=1;
      }
      dp[ni][nj]=min(dp[ni][nj],dp[i][j]+a+b);
    }
  }
  int ans=dp[n][0];
  cout<<ans<<endl;
}