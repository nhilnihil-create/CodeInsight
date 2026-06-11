#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}

class comb{
  vector<ll> f,fr;
  ll MOD_;
  public:
  //a^(p-1) = 1 (mod p)(p->Prime numbers)
  //a^(p-2) = a^(-1)
  ll calc(ll a,ll b,ll p){//a^(b) mod p   
    if(b==0)return 1;
    ll y = calc(a,b/2,p);y=(y*y)%p;
    if(b & 1) y = (y * a) % p;
    return y;
  }
  void init(ll n,ll mod){//input max_n
    MOD_ = mod;
    f.resize(n+1);
    fr.resize(n+1);
    f[0]=fr[0]=1;
    for(ll i=1;i<n+1;i++){
      f[i] = (f[i-1] * i) % mod;
    }
    fr[n] = calc(f[n],mod-2,mod);
    for(ll i=n-1;i>=0;i--){
      fr[i] = fr[i+1] * (i+1) % mod;
    }
  }
  ll nCr(ll n,ll r){
    if(n<0||r<0||n<r)return 0;
    return f[n] * fr[r] % MOD_ * fr[n-r] % MOD_;
  }//nHr = n+r-1Cr
};


int main(){

  ll x,y;
  cin >> x >> y;

  if((x+y)%3){
    cout << 0 << endl;
    return 0;
  }

  ll k = (x+y)/3;

  x -= k;
  y -= k;
  comb co;
  co.init(x+y+1,MOD);

  cout << co.nCr(x+y,x) << endl;


}
