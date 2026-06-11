#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> m >> n;
	int ans = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 22; j <= n; ++j) {
			if(j % 10 == 1 || j % 10 == 0) continue;
			int x = j, sum = 1;
			while(x) {
				sum = sum * (x % 10);
				x /= 10;
			}
			if(sum == i) {
				//cout << i << "-" << j << endl;
				ans ++;
			}
		}
	cout << ans << endl;
	return 0;
}