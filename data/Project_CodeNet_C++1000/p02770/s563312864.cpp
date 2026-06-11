#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(ll i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define SIGN(a) (a==0?0:(a>0?1:-1))

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ld,ld> pdd;

const ll INF=(1LL<<50);
#if __cplusplus<201700L
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
#endif
template<class T>
bool chmax(T& a,const T& b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
template<class T>
bool chmin(T& a,const T& b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}

void solve(long long k, long long q, std::vector<long long> d, std::vector<long long> n, std::vector<long long> x, std::vector<long long> m){
  vector<ll> sumd(k);
  sumd[0]=d[0];
  REP(d.size()-1){
    sumd[i+1]=sumd[i]+d[i+1];
  }
  For(times,q){
    const ll mod=m[times];
    ll nn=n[times]-1;
    ll zcnt=0;
    ll xx=x[times]%mod;
    vector<ll> dd(k),sumdd(k);
    REP(k){
      dd[i]=d[i]%mod;
      if(dd[i]==0)++zcnt;
    }
    sumdd[0]=dd[0];
    REP(k-1){
      sumdd[i+1]=sumdd[i]+dd[i+1];
    }
    ll lasta=xx+sumdd.back()*(nn/k)+(nn%k>0?sumdd[nn%k-1]:0);
    ll ans=nn-(nn/k)*zcnt;
    dump(ans);
    dump(lasta);
    REP(nn%k){
      if(dd[i]==0)--ans;
    }
    dump(zcnt);
    cout<<ans-lasta/mod<<endl;
  }
}

int main(){
  cout<<setprecision(1000);
  cin.tie(0);
  ios::sync_with_stdio(false);
    long long k;
    scanf("%lld",&k);
    long long q;
    scanf("%lld",&q);
    std::vector<long long> d(k-1-0+1);
    for(int i = 0 ; i < k-1-0+1 ; i++){
        scanf("%lld",&d[i]);
    }
    std::vector<long long> n(q);
    std::vector<long long> x(q);
    std::vector<long long> m(q);
    for(int i = 0 ; i < q ; i++){
        scanf("%lld",&n[i]);
        scanf("%lld",&x[i]);
        scanf("%lld",&m[i]);
    }
    solve(k, q, std::move(d), std::move(n), std::move(x), std::move(m));
    return 0;
}
