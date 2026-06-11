#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;cin>>N;
  ll MOD=1e9+7;
  
  ll a10=1,a9=1,a8=1;
  while(N){
    a10*=10;
    a9*=9;
    a8*=8;
    a10%=MOD;
    a9%=MOD;
    a8%=MOD;
    N--;
  }
  
  cout<<((a10-2*a9+a8)%MOD+MOD)%MOD<<endl;
}