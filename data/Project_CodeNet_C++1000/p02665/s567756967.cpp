#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define A_MAX 10000000000000

int main()
{
  int n;cin>>n;
  vector<ll> a(n+1);
  int i,j;
  rep(i,n+1)cin>>a[i];
  bool ok=true;
  ll left=1;
  vector<ll> marg(n+1);
  rep(i,n+1)
  {
    left-=a[i];
    if(left<0)
    {
      ok=false;
      break;
    }
    marg[i]=left;
    if(left>=A_MAX)
    {
      ok=true;
      for(j=i;j<=n;j++)
      {
        marg[j]=A_MAX;
      }
      break;
    }
    left*=2;
  }
  if(a[n]==0)ok=false;
  if(!ok)cout<<-1<<endl;
  else
  {
    ll ans=0;
    ll kuki=0;
    ll ed=a[n];
    for(i=n;i>=0;i--)
    {
      if(i!=0)
      {
        ed=kuki+a[i];
        ans+=(kuki+a[i]);
        kuki=min(marg[i-1],ed);
      }
      else ans++;
    }
    cout<<ans<<endl;
  }
  
}
