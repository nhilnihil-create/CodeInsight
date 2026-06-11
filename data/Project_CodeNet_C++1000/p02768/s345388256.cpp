 
/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define all(x)     x.begin(),x.end()
#define tc   int tt; scf(tt); while(tt--)
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
typedef double dd;
using namespace std;
const ll mod =1e9+7;
const int N = 1e6+7;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)


int fac[N],inv[N];

int me(int x, int n) 
{
  int res = 1;
  while(n) {
      if(n & 1) 
         res = (1LL * res * x) % mod;
      x = (1LL * x * x) % mod;
      n >>= 1;
  }
  return res;
}

int mi(int x, int m)
{
    return me(x, m-2);
}

void fact() 
{
  fac[0] = 1;

  rep(i, 1, N) 
     fac[i] = (1LL * fac[i - 1] * i) % mod;
   

  inv[N-1] = mi(fac[N-1], mod);

  for(int i = N - 1; i > 0; i--) 
    inv[i - 1] = (1LL * inv[i] * i) % mod;
   
}

int nCr(int n, int k) 
{
  if(k > n)
      return 0;

  int ans = (1LL * fac[n] * inv[k]) % mod;
  ans = (1LL * ans * inv[n - k]) % mod;

  return ans;
}



int main()
{
    
    fact();
   
    int n,a,b;
    scf(n),scf(a),scf(b);

    ll ans=me(2,n)-1;

    ll x=1,y=1;

    rep(i,n-a+1,n+1)
    x=x*i, x%=mod;

    rep(i,n-b+1,n+1)
    y=y*i,y%=mod;

    x*=inv[a];
    x%=mod;

    y*=inv[b];
    y%=mod;

    x+=y;

    x%=mod;

    ans=(ans-x+mod)%mod;
    ans+=mod;

    lprin((ans+mod)%mod);
}