#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),i##formax=(b);i<i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formax=(b);i>=i##formax;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define all(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define bitComb(a,n,k) for(int a##x,a##y,a=(1<<k)-1;a<(1<<n);a##x=a&-a,a##y=a+a##x,a=(((a&~a##y)/a##x)>>1)|a##y)
#define bit(n) (1LL<<(n))
#define randInt(l,r) (uniform_int_distribution<ll>(l,r)(rnd))
#define randDouble(l,r) (uniform_real_distribution<double>(l,r)(rnd))
#define dout(d) printf("%.12f\n",d)

typedef long long ll;
typedef __int128_t lll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T,class Y>ostream& operator<<(ostream&o,const pair<T,Y>&p){return o<<"("<<p.fi<<","<<p.se<<")";}
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
template<typename T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return (x%m+m)%m;}
ll modPow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isPrime(ll n){if(n<2||n%2==0)return n==2;lll t=n-1,d=t/(t&-t);for(lll a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){for(t=d,a=modPow(a,t,n);t!=n-1&&a!=1&&a!=n-1;a=a*a%n,t=t*2%n);if(a!=n-1&&t%2==0)return 0;}return 1;}
//V<ll>fac,rfac;void setFac(int n,int mod){fac=rfac=V<ll>(++n);fac[0]=1;FOR(i,1,n)fac[i]=fac[i-1]*i%mod;rfac[n-1]=modInv(fac[n-1],mod);FORR(i,n-1,1)rfac[i-1]=rfac[i]*i%mod;}
const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7;
const double PI = acos(-1);
const double EPS = 1e-10;
static random_device rd;
static mt19937 rnd(rd());

const int N = 1e5;
int n;
V<pll> v, v2;
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  FOR(i, 0, n){
    ll x, y;
    cin >> x >> y;
    if (!x&&!y) continue;
    v.pb(mp(x, y));
    v2.pb(mp( x,  y));
    v2.pb(mp( x, -y));
    v2.pb(mp(-x,  y));
    v2.pb(mp(-x, -y));
  }
  ll ans = 0;
  for(auto a:v2){
    ll sx=0, sy=0;
    for(auto b:v){
      ll op = a.fi*b.se-a.se*b.fi;
      ll ip = a.fi*b.fi+a.se*b.se;
      if(op>0 || op==0&&ip>0) sx+=b.fi, sy+=b.se;
    }
    maxs(ans, sx*sx + sy*sy);
  }
  dout(sqrt(ans));
}