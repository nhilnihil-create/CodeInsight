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
ll ketawa(ll a){ll r=0;while(a){r+=a%10;a/=10;}return r;}


vector<ll> enum_div(int n){//yakusu
  vector<ll> ret;
  for(ll i=1 ; i*i<=n ; ++i){
      if(n%i == 0){
        ret.push_back(i);
        if(i*i!=n)ret.push_back(n/i);
      }
  }
  return ret;
}

int main(){
  ll N,K,S=0;
  cin >> N >> K;
  vector<ll> A(N);
  for(auto &&a:A){
    cin >> a;
    S += a;
  }

  ll ans = 1;
  for(auto e:enum_div(S)){
    vector<ll> d;
    for(auto a:A)if(a%e)d.push_back(a%e);
    sort(d.begin(), d.end());
    ll pnum = 0;
    ll mnum = 0;
    for(auto a:d)mnum+=(e-a);
    if(mnum <= K  &&  abs(pnum-mnum)%e==0){
      ans = max(ans,e);
    }
    for(auto a:d){
      pnum += a;
      mnum -= (e-a);
      if(max(pnum,mnum) <= K && abs(pnum-mnum)%e==0){
        ans = max(ans,e);
      }
    }
  }
  cout << ans << endl;
}
