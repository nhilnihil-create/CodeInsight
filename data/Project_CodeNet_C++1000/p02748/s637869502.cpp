#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll A,B,M,maximum=200000,min1=100000,min2=100000;
  cin>>A>>B>>M;
  vector<ll> a(A);
  vector<ll> b(B);
  for(ll i=0;i<A;i++){
    cin>>a.at(i);
    min1=min(min1,a.at(i));
  }
  for(ll i=0;i<B;i++){
    cin>>b.at(i);
    min2=min(min2,b.at(i));
  }
  for(ll i=0;i<M;i++){
    ll x,y,c;
    cin>>x>>y>>c;
    maximum=min(maximum,(a.at(x-1)+b.at(y-1)-c));
  }
  cout<<min(min1+min2,maximum)<<endl;
  return 0;
}