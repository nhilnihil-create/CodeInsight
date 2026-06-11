#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int main(){
  ll n,ans=0; cin>>n;
  for(ll i=1;i<=n;i++){
    ll li=floor((long double)n/i);
    ans+=i*li*(li+1)/2;
  }
  cout<<ans<<endl;
}