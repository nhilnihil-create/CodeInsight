#include<iostream>
using namespace std;
using ll=long long;
int main(){

  ll N,A,B;
  cin>>N>>A>>B;
  ll group=N/(A+B);
  ll mod=N%(A+B);
  if(mod>=A)mod=A;
  cout<<group*A+mod;
  return 0;
}