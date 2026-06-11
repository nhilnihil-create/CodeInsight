#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
//------------------------------------------//


ll f(ll H){
  if(H==1) return 1;
  
  return 2*f(H/2) +1;
}

int main(){
  ll H;cin>>H;
  cout<<f(H)<<endl;
}