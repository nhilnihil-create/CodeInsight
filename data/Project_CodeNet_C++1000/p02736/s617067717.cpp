#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nCk(ll n,ll k){
  if((n&k)==k){return 1;}
  return 0;
}
int main(){
  ll N,a=0,b=0;
  string str;
  cin>>N>>str;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    vec.at(i)=str.at(i)-'0'-1;
    if(vec.at(i)==1){a++;}
    b+=nCk(N-1,i)*(vec.at(i)%2);
    b%=2;
  }
  if(b==1){cout<<1<<endl;return 0;}
  if(a!=0){cout<<0<<endl;return 0;}
  for(ll i=0;i<N;i++){
    vec.at(i)/=2;
    b+=nCk(N-1,i)*vec.at(i);
  }
  if(b%2==1){cout<<2<<endl;return 0;}
  cout<<0<<endl;return 0;
}