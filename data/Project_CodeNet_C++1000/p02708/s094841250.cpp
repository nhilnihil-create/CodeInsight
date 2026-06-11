#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
  long n,k,i,f,l;
  long sum1=0;
  long sum2=0;
  long r=0;
  cin>>n>>k;
  for(i=k;i<=n+1;++i){
    f=i*(i-1)/2;
    l=(n*2-i+1)*i/2;
    sum1=l-f+1;
    sum2=(sum2+sum1)%mod;
  }
  cout<<sum2;
}