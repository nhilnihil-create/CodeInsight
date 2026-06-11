#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  ll x=n%(a+b);
  ll y=n/(a+b);
  ll ans=a*y;
  if(a>x){
    ans+=x;
  }
  else{
    ans+=a;
  }
  cout<<ans<<endl;
}