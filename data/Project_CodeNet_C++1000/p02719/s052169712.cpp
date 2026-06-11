#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	ll n, k;
	cin >> n >> k;
	ll ans;
	ans = min(n % k, k - n % k);
	cout << ans << "\n";
	
	return 0;
}