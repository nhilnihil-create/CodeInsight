#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll cal(ll x) {
  ll a=1;
  for(ll i=0;i<x;i++) {
    a*=26;
  }
  return a;
}

 
int main() {
ll N;
  cin>>N;
  
  ll t=0;
  ll i=0;
  while(N>t) {
    i++;
    t+=cal(i);
  }
  t-=cal(i);
  ll mozisu=i;
  string S="abcdefghijklmnopqrstuvwxyz";
  for(ll j=0;j<mozisu;j++) {
    ll a=0;
while(N>t) {
t+=cal(i-1);
a++;
}
    cout<<S[a-1];
    t-=cal(i-1);
    i--;
  }
  
  cout<<endl;
}
 
  
