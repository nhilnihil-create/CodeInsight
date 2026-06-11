#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)



int main()
{
	ll n;
	cin >> n;
	vector<ll> d(n);
	rep(i, n) cin >> d[i];
	sort(d.begin(), d.end());
	ll k = n / 2;
	cout << d[k] - d[k-1] << "\n";

	return 0;
}