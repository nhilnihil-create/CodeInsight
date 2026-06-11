#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int k,a,b;
  cin>>k>>a>>b;
  for(int i=a;i<=b;i++){
    if(i%k==0){
      cout<<"OK"<<endl;
      return 0;
    }    
  }
  cout<<"NG"<<endl;
  return 0;
}
