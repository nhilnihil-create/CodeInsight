#include <bits/stdc++.h>
 
using namespace std;

#define M 998244353
#define pb emplace_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; ++i)
#define repn(i, st, ed) for(ll i=st; i<=ed; ++i)
#define repb(i, ed, st) for(ll i=ed; i>=st; --i)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define PI acosl(-1.0)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vec;
typedef vector<pll> vecp;
typedef map<ll, ll> mpll;


const int N = 1e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H) << endl;
  debug_out(T...);
}
#define LOCAL 3
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
ll ppow(ll x, ll y, ll mod)
{
  ll res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%mod;
    y = y >> 1;
    x = (x * x)%mod;
  }
  return res;
}

ll mul(ll x, ll y)
{
  return (((x%M)*(y%M))%M);
}

void solve()
{
	ll n;
	cin>>n;
	map<ll, ll> mp;
	vector<ll> v;
	ll mx = 0;
	rep(i, 0, n)
	{
		ll x;
		cin>>x;
		mp[x]++;
		v.pb(x);
		chmax(mx, x);
	} 
	if(mp[0] != 1 || v[0] != 0) {cout<<0<<endl;return;}          
	ll ans = 1;
	repb(i, mx, 1)
	{
		ll curr = mp[i];
		ll up = mp[i-1];
		ll tans  = ppow(up, curr, M);
		ans = mul(ans, tans);
	}
	cout<<ans<<endl;
}


int main()
{
	ll Tests = 1;
    //cin>>Tests;
    while(Tests--)
    {
    	solve();
    }
    return 0;
}