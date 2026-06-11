#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
ll gcd(ll p,ll q){
  if(p%q==0)return q;
  return gcd(q,p%q);
}
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  if(a+b+c>=22){
    cout<<"bust"<<endl;
    return 0;
  }
  cout<<"win"<<endl;
  return 0;
}