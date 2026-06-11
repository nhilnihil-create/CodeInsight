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
  ll N,M;
  cin>>N>>M;
  vector<P> vec(N);
  map<ll,vector<ll>> mp;//価値と日数
  priority_queue<ll> q;
  ll maxb=0;
  for(ll i=0;i<N;i++){
    ll a,b;//aは何日かかるか、bは価値
    cin>>a>>b;
    vec.at(i)=make_pair(a,b);
    mp[a].push_back(b);
    if(b>maxb){maxb=b;}
    if(a==1){q.push(b);}
  }
  ll ans=0;
  vector<ll> work(M);
  for(ll i=1;i<=M;i++){//i日前
    if(q.empty()){work.at(M-i)=0;}
    else{work.at(M-i)=q.top();q.pop();}
    if(i<M){
      for(ll j=0;j<(ll)mp[i+1].size();j++){
        q.push(mp[i+1].at(j));
      }
    }
    ans+=work.at(M-i);
  }
  cout<<ans<<endl;
}