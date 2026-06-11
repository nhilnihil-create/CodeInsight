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

	ll x, k, d;
	cin >> x >> k >> d;

	ll moves_req = abs(x) / d;
	// debug(moves_req)
	ll pos;
	if(moves_req >= k)
		pos = abs(x) - k * d;
	else
	{
		pos = abs(x) - moves_req * d;
		ll moves_left = k - moves_req;
		if(moves_left % 2 == 1)
			pos = abs(pos - d);
	}

	cout << pos << endl;
}