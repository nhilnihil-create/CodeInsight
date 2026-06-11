#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

struct query { ll n; ll x; ll m; };

int main() {
  int k, q; cin >> k >> q;
  ll d[k]; rep(i,k) cin >> d[i];
  query qu[q]; rep(i,q) { ll n, x, m; cin >> n >> x >> m; qu[i] = {n,x,m}; }
  rep(i,q) {
    ll result = qu[i].n-1;
    ll nd[k] = {}; rep(j,k) nd[j] = d[j]%qu[i].m;
    // debug(nd,nd+k);
    rep(j,k) if (nd[j]==0) result -= ((qu[i].n-1)+(k-1-j))/k;
    ll sum = qu[i].x;
    rep(j,k) sum += nd[j] * (((qu[i].n-1)+(k-1-j))/k);
    // cout << sum << endl;
    result -= sum/qu[i].m - qu[i].x/qu[i].m;
    cout << result << endl;
  }
  return 0;
}