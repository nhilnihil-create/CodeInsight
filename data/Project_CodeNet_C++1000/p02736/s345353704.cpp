#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=10e+7;
ll nature(ll a){
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll nCk(ll n,ll k){
  if((n&k)==k){return 1;}
  else{return 0;}
}
int main(){
  ll N,aa=0,ans=0;
  string str;
  cin>>N>>str;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    vec.at(i)=str.at(i)-'0'-1;
    if(vec.at(i)==1){aa++;}
    ans+=nCk(N-1,i)*(vec.at(i)%2);
  }
  if(ans%2==1){cout<<1<<endl;return 0;}
  if(aa!=0){cout<<0<<endl;return 0;}
  ans=0;
  for(ll i=0;i<N;i++){
    vec.at(i)/=2;
    ans+=nCk(N-1,i)*vec.at(i);
  }
  if(ans%2==1){cout<<2<<endl;return 0;}
  cout<<0<<endl;return 0;
}