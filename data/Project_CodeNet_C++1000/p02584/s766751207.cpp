#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;

int main()
{
	ll x, k, d;
	cin >> x >> k >> d;
	if(x < 0LL) x = -x;
	ll s = x / d;
	if(s > k) s = k;
	x -= (s * d);
	k -= s;
	cout << (k % 2 == 0 ? x : abs(x - d)) << endl;
	return 0;
}