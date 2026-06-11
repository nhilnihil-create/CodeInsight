#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
const int N=1e5+3;
int dp0[N];//i digits from top  match s
int dp1[N];//not so
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  string s;
  cin>>s;
  dp0[0]=1;int n=s.length();
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0')
    {
      dp0[i+1]=dp0[i];
      dp1[i+1]=(3*dp1[i])%mod;//00 10 01
    }
    else
    {
      dp0[i+1]=(2*dp0[i])%mod;//cqn use 1 or 0
      dp1[i+1]=(dp0[i]+dp1[i]*3)%mod;
    }
  }
  cout<<(dp0[n]+dp1[n])%mod;


}