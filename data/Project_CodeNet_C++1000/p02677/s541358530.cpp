//
//	Created by shamim_nik
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef tree<int,null_type,less<int>,rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;

#define PI 3.14159265358979323846264338327950L

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

// c^2 = a^2 + b^2 − 2.a.b.cosA

	ll a, b, h, m;
	cin >> a >> b >> h >> m;
	ldb angle = (ldb)((11 * m) - (60 * h)) / 2.0;
	// cout << angle << '\n';
	ldb a_b_cosa = 2 * a * b * cos((PI * angle) / 180);
	// cout << cosa << '\n';
	a *= a; b *= b;
	cout << fixed << setprecision(20) << sqrt((ldb)((a + b) - a_b_cosa)) << '\n';
	return 0;
}