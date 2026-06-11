#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
// Its  a Greedy Problem and we just going to k bigest elements as 0 and sum the rest;
int main()
{
  ll n,k,sum=0;
  cin>>n>>k;
  ll arr[n];
  for(int i=0;i<n;i++)
  {
    ll x;
    cin>>x;
    sum+=x;
    arr[i]=x;
  }
  
  sort(arr,arr+n);
  
  if(k==0)
    cout<<sum<<endl;
  else
  {
    if(n-k>0)
    {
      ll sum1=0;
      for(int j=0;j<n-k;j++)
      {
        sum1+=arr[j];
      }
      cout<<sum1<<endl;
    }
    else
    {
      cout<<0<<endl;
    }
  }
}
