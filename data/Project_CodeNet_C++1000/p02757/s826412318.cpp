#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

int n, a[200010];
ll mod;
string s;

long long extgcd(long long a,long long b,long long& x,long long& y)
{
  long long d = a;
  if(b != 0){
    d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }
  else
    x = 1,y = 0;
  return d;
}

long long mod_inv(long long a,long long m)
{
  long long x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

void solve() {
  ll ans = 0;
  if( mod == 2 || mod == 5 ) {
    rep(i,n) if( ( mod == 2 || mod == 5 ) && (s[i]-'0') % mod == 0 ) ans += (ll)( i + 1 );
  } else {
    vector<ll> a(n);
    ll pw10 = 1;
    for(int i=n-1;i>=0;--i) {
      a[i] = ( ( (s[i]-'0') * pw10 ) % mod + ((i+1<n)?a[i+1]:0) ) % mod;
      ( pw10 *= 10LL ) %= mod;
    }
    map<ll,ll> mp;
    rep(i,n) ++mp[a[i]];
    for(int i=n-1;i>=0;--i) {
      int v = ((i+1<n)?a[i+1]:0);
      if( mp.count(v) ) ans += mp[v];
      --mp[a[i]];
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> n >> mod;
  cin >> s;
  solve();
  return 0;
}
