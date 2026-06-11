//////////////////////////
//////////////////////////
////Please give me AC!////
////Please give me AC!////
//////////////////////////
//////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=998244353;
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
  ll N,S;
  cin>>N>>S;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
  }
  ll dp[3020][3020];
  dp[0][0]=1;
  for(ll i=1;i<=N;i++){
    for(ll j=0;j<=S;j++){
      dp[i][j]=dp[i-1][j]*2%MOD;
      if(j-A.at(i-1)>=0){
        dp[i][j]+=dp[i-1][j-A.at(i-1)]%MOD;
      }
      dp[i][j]%=MOD;
    }
  }
  cout<<dp[N][S]%MOD<<endl;
}