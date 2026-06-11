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
	ll h, n;
	cin >> h >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	if (h <= sum) cout << "Yes" << "\n";
	else  cout << "No" << "\n";

	return 0;
}