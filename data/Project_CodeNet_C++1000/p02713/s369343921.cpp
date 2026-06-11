#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  for(ll i=1;i<a+1;i++){
    b+=i;
  }
  
  ll c=0;
  if(a>=2){
    for(ll i=2;i<a+1;i++){
      for(ll j=1;j<i;j++){
        for(ll k=j;k<=j;k--){
          if(j%k==0&&i%k==0){
            c+=k;
            break;
          }
        }
      }
    }
    c=c*6;
  }
  ll d=0;
  if(a>=3){
    for(ll i=3;i<a+1;i++){
      for(ll j=2;j<i;j++){
        for(ll k=1;k<j;k++){
          for(ll l=k;l<=k;l--){
            if(i%l==0&&k%l==0&&j%l==0){
              d+=l;
              break;
            }
          }
        }
      }
    }
  d=d*6;
  }
  cout<<b+c+d<<endl;
}
