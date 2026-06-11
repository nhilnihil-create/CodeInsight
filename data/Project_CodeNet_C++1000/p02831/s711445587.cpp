#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
ll gcd(ll p,ll q){
  if(p%q==0)return q;
  return gcd(q,p%q);
}
int main() {
  ll a,b;
  cin>>a>>b;
  cout<<a*b/gcd(a,b)<<endl;
}