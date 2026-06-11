#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x, y;
	cin >> x >> y;
	vector<int>c = { 300000,200000,100000,0 };
	if (x >= 4)x = 4;
	if (y >= 4)y = 4;
	ll ans = c.at(x - 1) + c.at(y - 1);
	if (x == 1 && y == 1)ans += 400000;
	cout << ans << endl;

}