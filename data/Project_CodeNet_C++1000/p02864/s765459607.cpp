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
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
template<typename A, size_t N, typename T>void Fill(A (&a)[N], const T &val){fill((T*)a, (T*)(a+N), val);}

const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7; //998244353;
const int N = 302;
int n, T, H[N];
ll DP[N][N], DP2[N][N];
ll mi[N+1];
V<int> z={0};

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> T;
  FOR(i, 0, n){
    cin >> H[i];
    z.pb(H[i]);
  }
  uniq(z);
  int C = sz(z);
  mi[C] = LINF;
  FOR(i, 0, n) H[i] = lower_bound(all(z), H[i]) - z.begin();
  Fill(DP, LINF);
  FOR(i, 0, C) DP[0][i] = z[i];
  FOR(i, 0, n){
    Fill(DP2, LINF);
    FOR(j, 0, T+1){
      FORR(k, C-1, 0) mi[k] = min(mi[k+1], DP[j][k]);
      ll m = LINF;
      FOR(k, 0, C){
        mins(m, DP[j][k]-z[k]);
        if(k==H[i]) mins(DP2[j][k], min(mi[k], m+z[k]));
        DP2[j+1][k] = min(mi[k], m+z[k]);
      }
    }
    swap(DP, DP2);
  }
  ll ans = LINF;
  FOR(i, 0, T+1)FOR(j, 0, C) mins(ans, DP[i][j]);
  cout << ans << endl;
}