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
	ll n;
	cin >> n;
	vector<ll> a(n,0);
	ll x;
	rep(i, n-1)
	{
		cin >> x;
		a[x - 1]++;
	}
	


	rep(i, n )
	{
		cout << a[i] << "\n";
	}

	return 0;
}