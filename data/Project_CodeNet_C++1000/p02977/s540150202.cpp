#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)
#define pb push_back
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
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

void Yn(bool z){cout<<(z?"Yes":"No")<<endl;/*exit(0);/**/}
lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
//V<ll>F,R;void setF(int n,int mod){F=R=V<ll>(++n);F[0]=1;FOR(i,1,n)F[i]=F[i-1]*i%mod;R[n-1]=modInv(F[n-1],mod);FORR(i,n-1,1)R[i-1]=R[i]*i%mod;}
//ll comb(int a,int b,int m){return a<b||b<0?0:F[a]*R[b]%m*R[a-b]%m;}

const int IINF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7; //99844353;
const int N = 1e5;
int n, z[N];
void f(int a, int b){
  cout << a+1 << " " <<  b+1 << endl;
}
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  if(pcnt(n)==1){
    Yn(false);
    return 0;
  }
  Yn(true);
  if(n%4==0){
    V<int> v;
    FOR(i, 0, n-1) v.pb(i);
    FOR(i, 0, 20) if((1<<i)&n) z[(1<<i)-1] = 1;
    sort(all(v), [](auto const& l, auto const& r) { return z[l]>z[r];});
    FOR(i, 0, sz(v)-1) f(v[i], v[i+1]);
    f(v.back(), v[0]+n);
    FOR(i, 0, sz(v)-1) f(v[i]+n, v[i+1]+n);
    f(v[0], n-1);
    f(v[pcnt(n)-1], n*2-1);
    return 0;
  }
  int m = (n+1)/4*4-1;
  FOR(i, 0, m-1) f(i, i+1);
  f(m-1, n);
  FOR(i, 0, m-1) f(i+n, i+1+n);
  if(n%4==3) return 0;
  f(0, m);
  f(m, m+1);
  f(0, m+n+1);
  f(m+n+1, m+n);
  if(n%4==1) return 0;
  f(1, m+2);
  f(m+n+1, m+n+2);
}