#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,k,d;

int main(){
  cin>>x>>d>>k;
  x=llabs(x);
  if(x/k>=d)cout<<x-k*d<<'\n';
  else{
    d-=x/k,x%=k;
    if(d%2==0)printf("%lld\n",x);
    else printf("%lld\n",k-x);
  }
  return 0;
}