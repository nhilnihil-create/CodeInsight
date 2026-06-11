#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#define endl "\n"
#define debug(x) cout << #x << " : " << x << endl;
#define debug2(x, y) cout << #x << " : " << x  << ", " << #y << " : " << y << endl;
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0);
typedef long long ll;
using namespace std;

int main()
{
	FASTIO

	ll n;
	cin >> n;

	ll maxm = 0;
	ll ans = 0;
	for(ll i = 0; i < n; i ++)
	{
		ll val;
		cin >> val;

		if(val > maxm)
			maxm = val;
		else
			ans += (maxm - val);
	}	

	cout << ans << endl;
}