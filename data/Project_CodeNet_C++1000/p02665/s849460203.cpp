#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
	vector<ll>a(n+1);
	rep(i,n+1)cin>>a[i];
	ll ans=0;
	vector<ll>b(n+1);
	b[n]=a[n];
	for(int i=n-1;i>=0;--i){
		b[i]=b[i+1]+a[i];
	}
	ll pre=1;
	rep(i,n+1){
		ll add=min(b[i],pre);
		if(add<a[i]){
			cout<<-1;
			return;
		}
		ans+=add;
		add-=a[i];
		pre=add*2;
	}
	cout<<ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
