#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

ll GCD(ll a, ll b){
  if(a < b){ swap (a,b);}  
  if(a % b==0){return b;}
  else{return GCD( a % b,b);}
}

int main() {
  ll a,b; cin>>a>>b;
  ll g= GCD(a,b);
  ll c=1;
  for(ll i=2; i<=pow(g,0.5); i++){
    if(g % i==0){
      while(true){
        if(g % i !=0){ c++; break;}
        g/=i;
      }
    }
  }
  if(g!=1){c++;}
  cout<<c;
}    