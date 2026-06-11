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
	ll x,y;
	cin >> x;
	ll p, q;
	p = (x - x % 500) / 500;
	y = x - p * 500;
	q = (y - y % 5) / 5;
	ll ans;
	ans = 1000 * p + 5 * q;
	cout << ans << "\n";

	return 0;
}