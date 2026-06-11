#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
 
template <class T> using V = vector<T>;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
const long long INF = 1LL << 60;
 
using ll = long long;
using db = double;
using st = string;
using ch = char;
using bl = bool;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
using vbl = V<bl>;
 
 
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define rFOR(i,a,b) for(ll i=(a);i>(b);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(b);i+=2)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define M(a,b) max(a,b)
#define rM(a,b) min(a,b)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl;
#define ci(a) cin>>a;
 

vll dp(100100);

ll sum(ll n) {
  ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0){
      break;
    }
  }
  return m;
}
 
 
const int MAX = 510000;
const int MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
 
#define comuse Comuse()
 
ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
 
 
 
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}
 
 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll mod=1000000007;
  ll N; ci(N)
  ll n=2*N;
  st s; ci(s)
  bl b=true;
  vll A(n);
  ll l=1;
  ll r=0;
  A[0]=1;
  FOR(i,1,n){
    if(s[i]==s[i-1]){
      A[i]=-A[i-1];
    }
    else{
      A[i]=A[i-1];
    }
    
    if(A[i]==1){
      l++;
    }
    else{
      r++;
    }
  }
  
  ll a=0;
  FOR(i,0,n){
    a+=A[i];
  }
  
  if(a!=0||s[0]=='W'||s[n-1]=='W') b=false;
  
  ll ans=1;
  l=0;
  r=0;
  FOR(i,0,n){
    if(A[i]==1){
      l++;
    }
    else{
      ans*=(l-r);
      ans%=mod;
      r++;
    }
  }
  
  FOR(i,1,N+1){
    ans*=i;
    ans%=mod;
  }
  
  if(b){
    co(ans)
  }
  else{
    co(0)
  }
}