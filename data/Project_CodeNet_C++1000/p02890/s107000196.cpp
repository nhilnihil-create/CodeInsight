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
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  
  unordered_map<ll,ll> um;

  for(auto x:a){
    um[x]++;
  }
  vector<ll> vec;
  for(auto p:um){
    vec.push_back( p.second );
  }
  sort(begin(vec),end(vec),greater<ll>());
  vector<ll> total;
  
  //for(auto x:vec) cout << x << " ";
  for(ll i=0;i<vec.size();i++){
    auto x=vec[i];
    if(i==0) total.push_back(x);
    else total.push_back( total.back() + x );
  }
  /*
  for(auto x:vec) cout << x << " ";
  cout << endl;
  for(auto x:total) cout << x << " ";
  cout << endl;
  //*/

  //rep1(i,vec.size()){
    rep1(i,n){
    //cout << "i:" << i << endl;
    if(i==1){
      cout << n << endl;
    }
    else if(i<=vec.size()){
      
      ll r=total.back();
      ll l=vec[i-1];
      //cout << l << "," << r << endl;
      ///*
      //while(r-l>1){
      ll res;
      while(r-l>0){
        ll piv=l+(r-l)/2;
        //cout << l << "," << r << endl;
        //cout << "piv:" << piv << endl;        
        auto itr=upper_bound( begin(vec),end(vec),piv,greater<ll>() );
        //cout << *itr << endl;
        auto idx = min((ll)distance(begin(vec),itr),i-1LL);
        ll pre=0;
        if(idx>0){
          pre=total[idx-1];
        }
        //cout << "idx:"<< idx << endl;
        auto val = piv * ( i-1 - idx + 1 ) - ( total[i-1] - pre );

        //cout << val << endl;
        //cout << total.back() - total[i-1] << endl;
        if(r==l){
          res=l;
          break;
        }
        else if(r-l==1){
          itr=upper_bound( begin(vec),end(vec),r,greater<ll>() );
          //cout << *itr << endl;
          idx = min((ll)distance(begin(vec),itr),i-1LL);
          pre=0;
          if(idx>0){
            pre=total[idx-1];
          }
          auto rval=r * ( i-1 - idx + 1 ) - ( total[i-1] - pre );
          //cout << r << endl;
          //cout << "rval:"<< rval << endl;
          if( rval <= total.back() - total[i-1] ){
            res=r;
            break;
          }
          else{
            res=l;
            break;
          }
        }

        if( val > total.back() - total[i-1] ){
          r=piv;
        }
        else{
          l=piv;
        }
        
        //break;
      }
      if(r==l) res=l;
      cout << res << endl;
      /*
      cout << l << "," << r << endl;
      auto itr=upper_bound( begin(vec),end(vec),piv,greater<ll>() );
      
      auto idx = min((ll)distance(begin(vec),itr),i-1LL);
      ll pre=0;
      if(idx>0){
        pre=total[idx-1];
      }
      auto val = r * ( i-1 - idx + 1 ) - ( total[i-1] - pre );
        if( val > total.back() - total[i-1] ){
          cout << l << endl;
        }
        else{
          cout << r << endl;
        }      
      //*/
    }
    else{
      cout << 0 << endl;
    }
  }

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
