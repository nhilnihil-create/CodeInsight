#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000007
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
#endif

  ll n,k;
  cin>>n>>k;
  vector<ll> v(n+1);
  v[0]=1;
  ll p=2;
  for(int i=1;i<=n;i++)
  {
    v[i]=p+v[i-1];
    p++;
  }

  ll count=0;
  for(int i=k;i<=n;i++)
  {
    ll sum1=v[i-1];
    ll sum2=v[n]-v[n-i];
    ll t=sum2-sum1+1;
    count=(count+t)%N;
  }

  count=(count+1)%N;
  cout<<count<<endl;

  return 0;
}