#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const long long int MOD = 1e9 + 7;

long long int mypow(long long int a,long long int n)
{
	long long int res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res = ((res%MOD)*(a%MOD) % MOD) % MOD;
			res %= MOD;
		}
		a = ((a%MOD)*(a%MOD) % MOD) % MOD;
		a %= MOD;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int n, a, b;

	cin >> n >> a >> b;

	long long int res = mypow(2,n);
	res -= 1;
	if (res < 0)
	{
		res += MOD;
	}

	long long int A = 1;

	if (a <= n - a)
	{
		long long int temp2 = a;
		long long int temp1 = n;
		while (temp2 > 0)
		{
			A = ((A%MOD)*(temp1%MOD) % MOD) % MOD;
			A %= MOD;
			A = ((A%MOD)*(mypow(temp2,MOD-2)%MOD) % MOD) % MOD;
			A %= MOD;
			temp1--;
			temp2--;
		}
		res -= A;
		if (res < 0)
		{
			res += MOD;
		}
	}
	else
	{
		long long int temp2 = n - a;
		long long int temp1 = n;
		while (temp2 > 0)
		{
			A = ((A%MOD)*(temp1%MOD) % MOD) % MOD;
			A %= MOD;
			A = ((A%MOD)*(mypow(temp2, MOD - 2) % MOD) % MOD) % MOD;
			A %= MOD;
			temp1--;
			temp2--;
		}
		res -= A;
		if (res < 0)
		{
			res += MOD;
		}
	}

	long long int B = 1;

	if (b <= n - b)
	{
		long long int temp2 = b;
		long long int temp1 = n;
		while (temp2 > 0)
		{
			B = ((B%MOD)*(temp1%MOD) % MOD) % MOD;
			B %= MOD;
			B = ((B%MOD)*(mypow(temp2, MOD - 2) % MOD) % MOD) % MOD;
			B %= MOD;
			temp1--;
			temp2--;
		}
		res -= B;
		if (res < 0)
		{
			res += MOD;
		}
	}
	else
	{
		long long int temp2 = n - b;
		long long int temp1 = n;
		while (temp2 > 0)
		{
			B = ((B%MOD)*(temp1%MOD) % MOD) % MOD;
			B %= MOD;
			B = ((B%MOD)*(mypow(temp2, MOD - 2) % MOD) % MOD) % MOD;
			B %= MOD;
			temp1--;
			temp2--;
		}
		res -= B;
		if (res < 0)
		{
			res += MOD;
		}
	}

	cout << res << '\n';

	return 0;
}