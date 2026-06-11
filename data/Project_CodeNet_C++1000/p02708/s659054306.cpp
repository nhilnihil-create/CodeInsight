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
#define ll unsigned long long int
#define test long int t;cin>>t; while(t--)
#define um unordered_map
#define en '\n'
#define us unordered_set
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
	//_______________________________-code starts-______________________________________________________________________________

	int n, k;
	cin >> n >> k;
	int sum = 0;
	int var1 = k * (k - 1) / 2;
	int var2 = n * (n + 1) / 2;
	//cout << var1 << " " << var2 << en;
	int ans = 0;

	for (int i = k; i <= n + 1; i++)
	{
		// int x = i * (i - 1) / 2;
		// int y = i * n - i * (i - 1) / 2;
		//cout << x << " " << y << en;
		//cout << n + 1 - i << en;
		int z = (i  * (n + 1 - i)  + 1) ;
		//cout << z << en;
		ans = (ans + z) % mod;
	}
	ans = ans % mod;
	cout << ans << en;
	//cout << ans % mod << en;

	// rep(i, var1, var2)
	// {
	// 	ans += (BE(10, 100, mod) + i % mod) % mod;
	// 	ans = ans % mod;
	// }

	//cout << ans << en;



	return 0;
}
