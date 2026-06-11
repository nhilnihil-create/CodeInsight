#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')'<<' ';cout<<endl
#define FOR(i,a,b) for (ll i=(ll)(a);i<(ll)(b);++i)
#define OUT(x) cout<<x<<endl
#define OUTP(x) cout<<'('<<x.first<<','<<x.second<<')'<<endl;
#define REP(i,n) FOR(i,0,n)
#define YES(cond) cond ? OUT("YES") : OUT("NO")
#define Yes(cond) cond ? OUT("Yes") : OUT("No")

template<class T> T gcd(const T x,const T y){if(!y){return x;}return gcd(y,x%y);}
template<class T> T lcm(const T x,const T y){return x/gcd(x,y)*y;};
template<class T> T modpow(T x,T n,const T mod) {
  T res=1;while(n>0){if(n%2)res=res*x%mod;x=x*x%mod;n/=2;};return res;
}
template<class T> T modinv(T x,const T mod){return modpow(x,mod-2,mod);}
template<class T> bool alltrue(const T &a){return all_of(ALL(a),[](bool x){return x;});}
template<class T> bool anytrue(const T &a){return any_of(ALL(a),[](bool x){return x;});}
template<class T> bool contain(const T &a,const T &b){for(auto x:b){if (a.find(x)==a.end()){return false;}}return true;}
template<class T> bool mmax(T &m,const T q){ if (m < q) {m = q; return true;} else return false; }
template<class T> bool mmin(T &m,const T q){ if (m > q) {m = q; return true;} else return false; }
template<class T> int siz(const T &a) {return (int)a.size();}
template<class T> set<T> devisers(T n) {
  set<T> res;for(T i=1;i<(T)sqrt(n)+1;i++){if(n%i==0){res.insert(i);res.insert(n/i);}}return res;
}
template<class T> void concat(T &a, const T &b){a.insert(a.end(),ALL(b));}
template<class T> void getand(const T &a,const T &b,T &c) {
  set_intersection(ALL(a),ALL(b),inserter(c,c.end()));
}
template<class T> void getor(const T &a,const T &b,T &c) {
  set_union(ALL(a),ALL(b),inserter(c,c.end()));
}
template<class T> void getdiff(const T &a,const T &b,T &c) {
  set_difference(ALL(a),ALL(b),inserter(c,c.end()));
}
template<class T> T deg2rad(T deg) {return deg*2*M_PI/360;}
template<class T> T rad2deg(T rad) {return rad*360/(2*M_PI);}

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD=1e9+7;
const ll MAX=5e6;

int main() {
  ll N,K;cin>>N>>K;
  vector<ll> AS(N);
  vector<ll> sumAS(N+1,0);
  REP(i,N) cin>>AS[i];
  REP(i,N) sumAS[i+1] = sumAS[i]+AS[i];
  REP(i,N+1) {
    sumAS[i] -= i;
    sumAS[i] %= K;
  }

  ll ans = 0;
  map<ll,ll> mp;
  REP(i,N+1) {
    ans += mp[sumAS[i]];
    mp[sumAS[i]]++;
    if (i>=K-1) mp[sumAS[i-K+1]]--;
  }
  OUT(ans);

  return 0;
}