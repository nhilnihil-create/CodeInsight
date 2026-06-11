#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
ll gcd(ll p,ll q){
  if(p%q==0)return q;
  return gcd(q,p%q);
}
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  ll c=0;
  for(ll i=0;i<b/2;i++){
    if(a.at(i)!=a.at(b-1-i)){
      c+=1;
    }
  }
  cout<<c<<endl;
  return 0;
}
