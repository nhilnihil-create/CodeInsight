#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

ll mod_inv(ll a)
{
  ll ret=1;
  ll left=MOD-2;
  ll ks=a;
  while(left>0)
  {
    if(left%2==1)
    {
      ret=(ret*ks)%MOD;
    }
    ks=(ks*ks)%MOD;
    left/=2;
  }
  return ret;
}

int main()
{
  string s;cin>>s;
  vector<ll> dp(s.size()+1,0);
  dp[0]=0;
  int i;
  ll bef1s=1;
  ll n3=1;
  ll ks=3;
  ll left=s.size()-1;
  while(left>0)
  {
    if(left%2==1)
    {
      n3=(n3*ks)%MOD;
    }
    left/=2;
    ks=(ks*ks)%MOD;
  }
  rep(i,s.size()-1)
  {
    if(i==0)
    {
      dp[i+1]=n3;
      bef1s=(bef1s*2)%MOD;
    }
    else if(s[i]=='0')
    {
      dp[i+1]=dp[i];
    }
    else
    {
      dp[i+1]=(dp[i]+bef1s*n3)%MOD;
      bef1s=(bef1s*2)%MOD;
    }
    n3=(n3*mod_inv(3))%MOD;
  }
  if(s[s.size()-1]=='0')
  {
    dp[s.size()]=(dp[s.size()-1]+bef1s)%MOD;
  }
  else
  {
    dp[s.size()]=(dp[s.size()-1]+bef1s*3)%MOD;
  }
  
  cout<<dp[s.size()]<<endl;
}