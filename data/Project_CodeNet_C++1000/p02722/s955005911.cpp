#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll k,j,z;
  cin>>k;
  int ans=0;
  for(ll i=1;i*i<=k;i++){
    if(k%i==0){
      if(i==1){
        goto skip;
      }
      z=k;
      while(z%i==0){
        z/=i;
      }
      if(z%i==1){
        ans++;
      }
      skip:
      j=k/i;
      z=k;
      if(i!=j){
        while(z%j==0){
          z/=j;
        }
        if(z%j==1){
          ans++;
        }
      }
    }
    if((k-1)%i==0){
      if((k-1)/i!=i){
        ans++;
      }
      ans++;
      if(i==1||(k-1)/i==1){
        ans--;
      }
    }
  }
  cout<<ans<<endl;
}