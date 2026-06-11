#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[200050],dp2[200050];

int main(){
  string s;
  cin >> s;
  int n=s.size();
  dp[0]=1,dp2[0]=2;
  REP(i,1,n){
    if(s[i]=='0'){
      dp[i]=(3*dp[i-1])%mod;
      dp2[i]=dp2[i-1];
    }else{
      dp[i]=((3*dp[i-1])%mod+dp2[i-1])%mod;
      dp2[i]=(2*dp2[i-1])%mod;
    }
  }
  cout << (dp[n-1]+dp2[n-1])%mod << endl;
return 0;}