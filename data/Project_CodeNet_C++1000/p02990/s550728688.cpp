#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll X,ll Y,ll P){
  vector<ll> digit2(1000),XX(1000);
  ll I,N,mod;
  I=0;
  
  while(Y!=0){
    digit2.at(I)=Y%2;
    Y=Y/2;
    I++;
  }
  N=I;
  
  XX.at(0)=X%P;
  for(I=1;I<N;I++){
    XX.at(I)=(XX.at(I-1)*XX.at(I-1))%P;
  }
  
  mod=1;
  for(I=0;I<N;I++){
    if(digit2.at(I)==1){
      mod=(mod*XX.at(I))%P;
    }
  }
  
  if(mod<0){
    mod=mod+P;
  }
  
  return mod;
}

int main(){
  ll n,k;
  cin >> n >> k;
  if(k==1){
    cout << n << endl;
  }else{
    ll i,s=n-k+1,p=1000000007;
    cout << s << endl;
    for(i=2;i<=k;i++){
      s=(s*(k-i+1)*(n-k-i+2))%p;
      s=(s*power(i*(i-1),p-2,p))%p;
      cout << s << endl;
    }
  }
}