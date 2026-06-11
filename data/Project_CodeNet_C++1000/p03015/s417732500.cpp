#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string L;
  cin >> L;
  ll x=1;//すでにa+bがL以下であることが確定している分
  ll y=2;//まだ確定していない(つまりa+bの上からn桁がLと一致している)

  for(int i=1;i<L.size();i++){
    if(L[i]=='0'){
      x*=3;
      x%=mod;
    }
    else{
      x=x*3+y;
      x%=mod;
      y*=2;
      y%=mod;
    }
  }
  cout << (x+y)%mod << endl;

}