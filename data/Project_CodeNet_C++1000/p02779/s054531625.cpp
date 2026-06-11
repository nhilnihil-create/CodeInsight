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
	set<ll> a;
	ll x;
	rep(i, n)
	{
		cin >> x;
		a.insert(x);
	}

	if (a.size() == n) cout << "YES";
	else cout << "NO";
	cout << "\n";
	return 0;
}