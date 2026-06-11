#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

//prime factor o(sqrt(n))
struct prime_factor
{
	map<ll, int> primes;
	prime_factor(ll n = 1)
	{
		for(ll i = 2; i * i <= n; i++)
		{
			int cnt = 0;
			while (n % i == 0)
			{
				n /= i;
				cnt++;
			}
			if(cnt > 0)primes[i] = cnt;
		}
		if(n > 1)primes[n]++;
	}

	ll get_prod()
	{
		ll res = 1;
		for(auto e : primes)
		{
			res *= ll(pow(e.first, e.second));
		}
		return res;
	}

	void show_factor()
	{
		for(auto e : primes)
		{
			cout << "(" << e.first << ", " << e.second << ")" << endl;
		}
	}
};

int order_to_prime(ll n, ll p)
{
	int res = 0;
	while (n % p == 0)
	{
		n /= p;
		res++;
	}
	return res;
}

void solve()
{
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) 
	{
		cin >> a[i];
		a[i] /= 2;
	}
	prime_factor gcd_fact;
	int num_of_two = -1;
	rep(i, n)
	{
		auto cnt = order_to_prime(a[i], 2);
		if(num_of_two < 0)chmax(num_of_two, cnt);
		else if(num_of_two != cnt)
		{
			cout << 0 << endl;
			return;
		}

		ll tmp = a[i];
		for(auto e : gcd_fact.primes)
		{
			ll p = e.first;
			auto x = order_to_prime(tmp, p);
			chmax(gcd_fact.primes[p], x);
			tmp /= ll(pow(p, x));
		}
		prime_factor tmp_fact(tmp);
		for(auto e : tmp_fact.primes)
		{
			ll p = e.first;
			chmax(gcd_fact.primes[p], tmp_fact.primes[p]);
		}
	}
	ll g = gcd_fact.get_prod();
	ll ans = (m / g + 1)/ 2;
	cout << ans << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
