//////////////////////////////
//////////////////////////////
////                      ////
////  Please give me AC!  ////
////  Please give me AC!  ////
////                      ////
//////////////////////////////
//////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
using  UM=unordered_map<char,ll>;
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
  ll N;
  cin>>N;
  vector<string> s(N);
  vector<UM> vec(N);
  vector<ll> so(10);
  for(ll i=0;i<N;i++){
    string str;
    cin>>str;
    for(ll i=0;i<10;i++){
      so.at(i)=str.at(i);
    }
    sort(so.begin(),so.end());
    for(ll i=0;i<10;i++){
      str.at(i)=so.at(i);
    }
    s.at(i)=str;
  }
  ll ans=0;
  sort(s.begin(),s.end());
  for(ll i=1;i<N;i++){
    ll count=1;
    while(s.at(i)==s.at(i-1)){
      count++;
      i++;
      if(i>=N){break;}
    }
    ans+=count*(count-1)/2;
  }
  cout<<ans<<endl;
}