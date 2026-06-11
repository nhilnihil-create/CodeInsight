#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}

template<typename T, size_t sz>
struct Combination{
  using ll = long long;
  array<T, sz> fact;

  T mod;
  Combination(T mod):mod(mod){init();}

  void init(){
    fact[0]=1;
    for(int i=1;i<(int)sz;i++)
      fact[i]=(ll)fact[i-1]*i%mod;
  }

  T mod_fact(T n,T& e){
    e=0;
    if(n==0) return 1;
    T res=mod_fact(n/mod,e);
    e+=n/mod;
    if(n/mod%2!=0)return res*(mod-fact[n%mod])%mod;
    return res*fact[n%mod]%mod;
  }

  T mod_comb(T n,T k){
    if(n==k||k==0) return 1;
    T e1,e2,e3;
    T a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse<ll>((ll)a2*a3%mod,mod)%mod;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  string s;
  cin>>s;

  vector<int> as(n);
  for(int i=0;i<n;i++) as[i]=s[i]-'1';

  const int sz = 1e6+10;
  Combination<int, sz> C(2);

  int is_one=0;
  for(int i=0;i<n;i++)
    if(as[i]&1) is_one^=C.mod_comb(n-1,i);

  if(is_one){
    cout<<1<<newl;
    return 0;
  }

  for(int i=0;i<n;i++){
    if(as[i]==1){
      cout<<0<<newl;
      return 0;
    }
    as[i]/=2;
  }

  int is_two=0;
  for(int i=0;i<n;i++)
    if(as[i]&1) is_two^=C.mod_comb(n-1,i);

  cout<<is_two*2<<newl;
  return 0;
}
