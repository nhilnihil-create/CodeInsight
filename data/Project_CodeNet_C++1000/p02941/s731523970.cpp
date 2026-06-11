#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>
#define rep(i,n) (int i=0;i<(int)(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n),b(n);
	for rep(i, n)
		cin >> b[i];
	for rep(i, n)
		cin >> a[i];
	vector<bool> ju(n, true);
	priority_queue<pair<long long, int>> da;
	long long ans = 0;
	for rep(i, n) {
		da.push(make_pair(a[i], i));
		ju[i] = bool(a[i] == b[i]);
	}
	while (!da.empty()) {
		int x = da.top().second;
		da.pop();
		if (!ju[x]) {
			long long y = a[(x + 1) % n] + a[(x - 1 + n) % n];
			if (a[x] <= y) {
				ans = -1;
				break;
			}
			if ((a[x]-b[x]) % y==0) {
				ans += (a[x] - b[x]) / y;
				a[x] = b[x];
				ju[x] = true;
			}
			else {
				ans += a[x] / y;
				a[x] %= y;
				if (a[x] < b[x]) {
					ans = -1;
					break;
				}
				da.push(make_pair(a[x], x));
			}
		}
	}
	cout << ans << endl;
}