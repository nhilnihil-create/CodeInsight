#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;


template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;
//using namespace atcoder;

void solve(){
	ll t[2],a[2],b[2];
	rep(i,2)cin>>t[i];
	rep(i,2)cin>>a[i];
	rep(i,2)cin>>b[i];
	if(a[0]*t[0]+a[1]*t[1]==b[0]*t[0]+b[1]*t[1])cout<<"infinity\n";
	else if(a[0]*t[0]>b[0]*t[0]&&a[0]*t[0]+a[1]*t[1]>b[0]*t[0]+b[1]*t[1])cout<<0<<"\n";
	else if(a[0]*t[0]<b[0]*t[0]&&a[0]*t[0]+a[1]*t[1]<b[0]*t[0]+b[1]*t[1])cout<<0<<"\n";
	else{
		ll x=abs(a[0]-b[0])*t[0];
		ll y=abs(a[0]*t[0]+a[1]*t[1]-b[0]*t[0]-b[1]*t[1]);
		ll ans=x/y*2;
		if(x%y)ans++;
		cout<<ans<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
