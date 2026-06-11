#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
int main(){
  ll N,K,sum=0,yama=1;
  cin>>N>>K;
  string S;
  cin>>S;
  for(ll i=0;i<(ll)S.size()-1;i++){
    if(S.at(i)!=S.at(i+1)){yama++;}
  }
  if(yama==1){cout<<N-1<<endl;return 0;}
  if(yama==2){cout<<N-1<<endl;return 0;}
  if(N==1){cout<<0<<endl;return 0;}
  for(ll i=0;i<(ll)S.size();i++){
    if(i==0){
      if(S.at(0)=='L'){}
      else if(S.at(1)=='R'){sum++;}
    }
    else if(i==(ll)S.size()-1){
      if(S.at((ll)S.size()-1)=='R'){}
      else if(S.at((ll)S.size()-2)=='L'){sum++;}
    }
    else{
      if(S.at(i)=='L'){
        if(S.at(i-1)=='L'){sum++;}
      }
      if(S.at(i)=='R'){
        if(S.at(i+1)=='R'){sum++;}
      }
    }
  }
  //cout<<yama<<" "<<sum<<endl;
  if(yama>=2*K){
    cout<<min(N-1,sum+2*K)<<endl;
  }
  else{cout<<min(N-1,sum+yama+K)<<endl;}
}