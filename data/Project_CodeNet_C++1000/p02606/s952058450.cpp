#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
     ordered_set s;
     s.insert(1);
     cout<<*s.find_by_order(1); //print kth smallest element
     cout<<s.order_of_key(3);  //print number of strictly smaller element of 3;
*/
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define pi acos(-1)
#define bp __builtin_popcount
#define ll long long int
#define ld long double
#define endl '\n'
#define pii pair<ll , ll>
#define tii tuple<ll,ll,ll>
//aaaccess element of tuple ex. 3rd element(index 2) cout<< get<2>(tuppleName);

#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> >
#define minq priority_queue <int, vector<int>, greater<int> >
#define maxQueue priority_queue<ll>
#define pb push_back
#define mx3(a,b,c) max(a,max(b,c))
#define pf push_front
#define ff first
#define ss second
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
const ll N = 1000005;
const ll M = 1e6 + 10;
const ll mod = 998244353;

ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
ll modinv(ll n, ll p)
{
	return power(n, p - 2, p);
}
ll ncr(ll n, ll r, ll p)
{
	if (r == 0)
		return 1;
	int n1 = n;
	ll fac[n1 + 1];
	fac[0] = 1;
	for (int i = 1 ; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;

	return (fac[n] * modinv(fac[r], p) % p *
	        modinv(fac[n - r], p) % p) % p;
}
/*vector<bool> prime(N, true);
void sieve()
{
	for (int i = 2; i <= sqrt(N); ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = false;
			}
		}
	}
}/*

/*int Prime[M];
void MinPrimeFactor()
{
	for (ll i = 1; i < M; i++) Prime[i] = i;
	for (int p = 2; p * p <= M; p++)
	{
		if (Prime[p] == p)
		{
			for (int i = 2 * p; i <= M; i += p)
			{
				Prime[i] = min(p, Prime[i]);
			}
		}
	}
}*/

/*vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(Prime[x]);
		x = x / Prime[x];
	}
	return ret;
}
*/
bool isPowerOfTwo(int x)
{
	return (x && !(x & (x - 1)));
}
int main()
{
	FAST;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll i, j, k, c = 0, a, b, m, n, l, r, t, sum = 0, x;
	cin >> i >> j >> k;
	k = j / k - (i - 1) / k;
	cout << k;
	return 0;
}