#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max((x),(y))
#define mins(x,y) x=min((x),(y))
#define show(x) cout<<#x<<" = "<<(x)<<endl;
#define all(a) ((a).begin()),((a).end())
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define bit(n) (1LL<<(n))
typedef long long ll;
typedef __int128_t lll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T,class Y>using P=pair<T,Y>;
template<class T,class Y>ostream& operator<<(ostream&o,P<T,Y>&p){return o<<"("<<p.fi<<","<<p.se<<")";}
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}
template<class A,size_t N,class T>void Fill(A(&a)[N],const T&v){fill((T*)a,(T*)(a+N),v);}

const int MOD = 1e9+7; //998244353;

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m=MOD){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m=MOD){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
//V<ll>Fac,Rac;void setF(int n,int m=MOD){Fac=Rac=V<ll>(++n);Fac[0]=1;FOR(i,1,n)Fac[i]=Fac[i-1]*i%m;Rac[n-1]=modInv(Fac[n-1],m);FORR(i,n-1,1)Rac[i-1]=Rac[i]*i%m;}
//ll comb(int a,int b,int m=MOD){return a<b||b<0?0:Fac[a]*Rac[b]%m*Rac[a-b]%m;}

const int IINF = 1e9+6;
const ll LINF = 1e18;
const int N = 1e5;
int n, k;
ll c[N+1];
bool z[N+1];

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  for (int i=2; i<=N; ++i)if(!z[i])for(int j=i*2; j<=N; j+=i) z[j]=true;
  cin >> n >> k;
  FOR(i, 1, k+1) c[i] = modPow(k/i, n);
  FOR(i, 2, k+1)if(!z[i])FOR(j, 1, k/i+1) c[j] -= c[j*i];
  ll ans = 0;
  FOR(i, 1, k+1) ans += c[i]%MOD*i%MOD;
  cout << (ans%MOD+MOD)%MOD << endl;
}