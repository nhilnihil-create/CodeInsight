#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll x,k,l,d,ans;
  cin>>x>>k>>d;
  x=abs(x);
  l=x/d;
  if(l>k){
    ans=x-k*d;
  }else{
    if((k-l)%2==0){
      ans=x-l*d;
    }else{
      ans=abs(x-(l+1)*d);
    }
  }
  cout<<ans<<endl;
}