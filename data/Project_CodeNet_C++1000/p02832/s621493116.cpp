#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
ll gcd(ll p,ll q){
  if(p%q==0)return q;
  return gcd(q,p%q);
}
int main() {
  ll a;
  ll b=1;
  cin>>a;
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    if(c==b){
      b+=1;
    }
  }
  if(b==1){
    cout<<-1<<endl;
    return 0;
  }
  cout<<a-b+1<<endl;
  return 0;
}