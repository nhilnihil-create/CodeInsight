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

int main()
{
	ull n, a, b;
	cin >> n >> a >> b;
	ull c;
	c = a + b;
	ull x, y,z;
	x = (n - n % c) / c;
	y = n - x * c;
	if(y<=a)
	{
		z = y;
	}
	else
	{
		z = a;
	}

	ull ans;
	ans = a * x + z;
	cout << ans << "\n";


	return 0;
}