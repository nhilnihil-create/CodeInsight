#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define ff first
#define ss second
#define file_se_input  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pp long long int
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pb push_back
#define mp make_pair
#define pi 3.141592653589793238
#define eb emplace_back
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define zip(i,a,b) for(int i=a;i<b;i++)
#define rzip(i,a,b) for(int i=a;i>=b;i--)
#define ll unsigned long long int
#define test int t;cin>>t; while(t--)
#define um unordered_map
#define en '\n'
#define us unordered_set
typedef pair<int, int>     pii;
typedef pair<char, int>    pci;
typedef pair<char, char>   pcc;
typedef vector<pii>       vii;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define INF (1e18+5)
#define inf (1e9+5)
#define mod 1000000007


bool check_prime(long long n)
{
	int flag = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (n == 1)
		return false;
	else if (flag == 0 || n == 2 || n == 3)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int BE(int x, int n, int m) //function to calculate x raise to power n modulo m
{
	int result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = result * x % m;
		x = x * x % m;
		n = n / 2;
	}
	return result;
}

int factorial_modulo(int n)
{
	int result = 1;
	rep(i, 1, n)
	{
		result = result * i % mod;
		result = result % mod;
	}
	return result % mod;
}

int dp1[1000002], dp2[1000002];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	if (fopen("input.txt", "r"))
	{
		freopen ("input.txt" , "r" , stdin);
		freopen ("output.txt" , "w" , stdout);
	}
#endif
	//_______________________________-code starts-_______________________________________________

	int x, y;
	cin >> x >> y;
	if (x < y / 2)
	{
		//cout << "n" << en;
		cout << 0 << en;
	}
	else if (y < x / 2)
	{
		//cout << "o" << en;
		cout << 0 << en;
	}
	else if ((x + y) % 3)
	{
		//cout << "t" << en;
		cout << 0 << en;
	}
	else
	{
		int m = (2 * x - y) / 3;
		int n = (2 * y - x) / 3;
		//cout << m << en << n << en;
		int q = (factorial_modulo(m) % mod * factorial_modulo(n) % mod) % mod;
		int m1 = factorial_modulo(m) % mod;
		int n1 = factorial_modulo(n) % mod;
		// cout << "m1 " << m1 << en;
		// cout << "n1 " << n1 << en;
		q = (m1 * n1) % mod;
		q = q % mod;
		int q1 = BE(q, mod - 2, mod);
		int p = factorial_modulo(m + n);
		// cout << p << en;
		//cout << q << en;
		int ans = (p % mod * q1 % mod) % mod;
		cout << ans % mod << en;
	}


	return 0;
}

