#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll N;
  cin>>N;
  if(N%2!=0)cout<<0<<endl;
  else{
    ll ans=0,f=5;
    N/=2;
    while(N/f>0){
      ans+=N/f;
      f*=5;
    }
    cout<<ans<<endl;
  }
}