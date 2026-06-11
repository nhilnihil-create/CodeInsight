#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
using uif=uint_fast64_t;
using ll=long long int;

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll ,ll );
ll mod_add(ll ,ll );
ll mod_mul(ll ,ll );
ll mod_div(ll ,ll );
void make_fact(ll );
void make_invfact(ll );



int main(void){

  ll n;
  cin>>n;
  using pa=pair<ll,ll>;
  vector<pa> pos(n);
  rep(i,n) cin>>pos[i].first>>pos[i].second;

  map<double,pa> m;

  for(auto p:pos){
    //if(p.first==0 && p.second==0) continue;
    double theta = (double)atan2((double)p.second,(double)p.first);
    //cout << theta << endl;
    if(m.find(theta)==end(m)){
      m[theta]=p;
    }
    else{
      auto p2=m[theta];
      m[theta] = make_pair( p.first+p2.first,p.second+p2.second );
    }
  }
  ll ans=0;
  /*
  for(auto itr=begin(m);itr!=end(m);itr++){
    pa vec=make_pair(0,0);
    vec=make_pair(0,0);
    auto Ltheta = itr->first;
    //cout << "Ltheta:" << Ltheta << endl;
    if(Ltheta>0){
      for(auto itr2=itr; itr2!=end(m) ;itr2++){
        //cout << itr2->first << "::" << itr2->second.first << "," << itr2->second.second << endl;
        auto pv=vec;
        auto p2=itr2->second;
        vec= make_pair(pv.first+p2.first,pv.second+p2.second);
      }
      for(auto itr2=begin(m); itr2->first < Ltheta - M_PIl && itr2!=end(m) ;itr2++){
        //cout << itr2->first << "::" << itr2->second.first << "," << itr2->second.second << endl;
        auto pv=vec;
        auto p2=itr2->second;
        vec= make_pair(pv.first+p2.first,pv.second+p2.second);
      }
    }
    else{
      for(auto itr2=itr; itr2->first < Ltheta + M_PIl && itr2!=end(m) ;itr2++){
        //cout << itr2->first << "::" << itr2->second.first << "," << itr2->second.second << endl;
        auto pv=vec;
        auto p2=itr2->second;
        vec= make_pair(pv.first+p2.first,pv.second+p2.second);
      }
    }
    //cout << vec.first*vec.first + vec.second*vec.second << endl;

    ans=max(ans, vec.first*vec.first + vec.second*vec.second );
  }
  //*/

  vector<pa> arr;
  for(auto p:m) arr.push_back(p.second);
  ll N=arr.size();
  for(ll i=0;i<N;i++){
    for(ll j=i;j<N;j++){
      vector<pa> cand1;
      vector<pa> cand2;
      cand1.clear();
      cand2.clear();
      for(ll k=0;k<N;k++){
        if( k>=i && k<=j ){
          cand1.push_back( arr[k] );
        }
        else cand2.push_back( arr[k] );
      }
      pa v;
      v=make_pair(0,0);
      for(ll k=0;k<cand1.size();k++){
        auto p=cand1[k];
        v = make_pair( v.first + p.first ,v.second+p.second );
      }
      ans = max(ans,v.first*v.first+v.second*v.second);
      v=make_pair(0,0);
      for(ll k=0;k<cand2.size();k++){
        auto p=cand2[k];
        v = make_pair( v.first + p.first ,v.second+p.second );
      }
      ans = max(ans,v.first*v.first+v.second*v.second);

    } 
  }

  cout << std::setprecision(50) << sqrt(ans) << endl;

  return 0;

}

ll mod_pow(ll x,ll r){
  if(r==0) return 1;
  else if(r==1) return x%mod;
  else if(r%2==0){
    ll t=mod_pow(x,r/2)%mod;
    return t*t %mod;
  } 
  else{
    ll t=mod_pow(x,r/2)%mod;
    ll k= t*t %mod;
    return k*x%mod;
  } 
}
ll mod_add(ll a,ll b){
  return (a+b)%mod;
}

ll mod_mul(ll a,ll b){
  return (a*b)%mod;
}

ll mod_div(ll a,ll b){
  return mod_mul(a,mod_pow(b,mod-2));
}

void make_fact(ll n){
  fac[0]=1;
  rep(i,n){
    fac[i+1]=mod_mul(fac[i],i+1);
  }  
}

void make_invfact(ll n){
  invfac[n]= mod_pow( fac[n] ,mod-2);
  for(int i=n-1;i>=0;i--){
    invfac[i]=mod_mul(invfac[i+1],i+1);
  }

}
