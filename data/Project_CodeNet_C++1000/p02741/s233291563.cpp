#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back


int bexp(int a, int b)
{
	int res = 1;

	while (b)
	{
		if (b & 1) res = (res * a);

		a = (a * a); 
		b >>= 1;
	}
	return res;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

#define N 200010
#define MOD 1000000007

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int a[]= {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin >> k;
	cout << a[k - 1] << endl;
	return 0;
}