#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	priority_queue<tuple<long long, long long, int>> q; //(p, orig, num)
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		q.push(make_tuple(a, a, 0));
	}
	for (int i = 0; i < m; i++) {
		auto e = q.top();
		q.pop();
		if (get<0>(e) == 0)
			break;
		q.push(make_tuple(
					(long long)floor((long double)get<1>(e)/mypow(2, get<2>(e)+1)),
					get<1>(e),
					get<2>(e)+1));
	}
	long long ans = 0;
	while (!q.empty()) {
		auto e = q.top();
		q.pop();
		ans += get<0>(e);
	}
	cout << ans << endl;
	return 0;
}