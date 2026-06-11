#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll n;
ll Dp[2001];
long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    
ll solve(ll s)
{
  if(s == 1 || s == 2)
  return 0LL;
  if(s==3 || s==4 || s==5 || s==0)
  return 1LL;
  if(Dp[s]==-1){ Dp[s]=0;
  for(int j=3;j<=n;j++)
  {
      if(s-j>=0)
      Dp[s] = add(Dp[s],solve(s-j));
  }
  }
  //else Dp[s]++;
  return Dp[s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(Dp,-1,sizeof(Dp));
    cin>>n;
    cout<<solve(n);//<<endl;
    // for(int i=0;i<=n;i++)
    //cout<<Dp[i]<<" ";
    return 0;
}