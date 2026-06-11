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
vector<ll> pfvec;
ll iflediv=0,ledivexsit=0,sqrtX;
void pf(ll x){
  //pfvecは各約数についての指数を格納
  //ifledivはsqrtNより大きい、存在してもただ一つの約数
  //ledivexsitはifledivが存在するなら1、存在しないのならば0
  //sqrtXはxの平方根
  ll xcopy=x;
  sqrtX=sqrt(x);
  pfvec.resize(sqrtX);
  for(ll i=1;i*i<=xcopy;i++){
    while(x%i==0 && x>1 && prime(i)==1){
      x/=i;
      pfvec.at(i-1)++;
      if(x==1){break;}
    }
    if(xcopy%i==0 && prime(xcopy/i)==1 && x%(xcopy/i)==0 && x>1){
      x/=(xcopy/i);
      ledivexsit++;
      iflediv=xcopy/i;
      break;
    }
  }
}
int main(){
  ll N,ans=1;
  cin>>N;
  ll Ncopy=N;
  pf(N);
  for(ll i=2;i<=sqrtX;i++){
    if(N%i!=0){continue;}
    //cout<<pfvec.at(i)<<endl;
    while(N%i==0){N/=i;}
    if(N%i==1){ans++;}
    N=Ncopy;
  }
  N--;
  //cout<<ans<<endl;
  ll n=N,memo=0,count=0,sqrtN=sqrt(N);
  vector<ll> vec(sqrtN);
  for(ll i=1;i*i<=n;i++){
    ll rock=N;
    while(N%i==0 && N>1 && prime(i)==1){
      N/=i;
      vec.at(i-1)++;
      if(N==1){break;}
    }
    if(n%i==0 && prime(n/i)==1 && N%(n/i)==0){
        N/=(n/i);
        count++;
        memo=n/i;
        break;
    }
  }
  ll rock=1;
  for(ll i=0;i<sqrtN;i++){
    rock*=(vec.at(i)+1);
  }
  rock*=(count+1);
  cout<<rock+ans-1<<endl;
}