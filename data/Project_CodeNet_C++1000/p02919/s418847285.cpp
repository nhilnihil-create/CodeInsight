#include <bits/stdc++.h>
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

void solve()
{
	int n;
	cin>>n;
	vector<pair<ll,ll>>p(n);
	rep(i,n){
		int x;
		cin>>x;
		p[i]={x,i};
	}
	sort(rall(p));
	multiset<ll>st;
	st.emplace(-1);
	st.emplace(-1);
	st.emplace(n);
	st.emplace(n);
	ll ans=0;
	rep(i,n){
		st.emplace(p[i].second);
		auto itr=st.lower_bound(p[i].second);
		ll a=*prev(itr,2),b=*prev(itr),c=*next(itr),d=*next(itr,2),x=*itr;
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<"\n";
		ans+=p[i].first*((d-c)*(x-b)+(b-a)*(c-x));
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
