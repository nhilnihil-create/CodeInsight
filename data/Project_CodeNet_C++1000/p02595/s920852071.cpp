#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long int

int main()
{
	int n, ans = 0;
	ll x, y, d;
	ll tmp;
	cin >> n >> d;
	tmp = (ll)d*d;
	rep(i, n) {
		//cin >> x[i] >> y[i];
		cin >> x >> y;
		if ((x*x + y*y) <= (d*d)) ans++;
	}

	//auto sqroot = [](int x, int y) {return x*x + y*y;};
	//rep(i, n) {
	//	ans_value = sqroot(x[i], y[i]);
	//	if (sqroot(x[i], y[i]) <= d*d) ans++;
	//}
	cout << ans << endl;
	return 0;
}
