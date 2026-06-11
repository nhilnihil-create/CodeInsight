#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  if(n%2==1){cout<<0;}
  else{
    ll a,ans=0,i=1;
    while(true){
      ll p=pow(5,i);
      a=n/p; 
      if(a%2==0){a/=2;}
      else{a=(a-1)/2;}
      ans+=a;
      i++;
      if(n<p)break;
    }
    cout<<ans;
    
  }
}