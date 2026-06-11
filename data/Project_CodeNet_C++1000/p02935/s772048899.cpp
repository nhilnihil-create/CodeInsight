#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	rep(n, v);
	sort(v.begin(), v.end());
	double sum = 0;
	for (ll i = n - 1; 1 <= i ; i--)
	{
		sum += v[i] / pow(2, n-i);
	}
	sum += v[0] / pow(2, n - 1);
	cout << sum << "\n";
	
	return 0;
}