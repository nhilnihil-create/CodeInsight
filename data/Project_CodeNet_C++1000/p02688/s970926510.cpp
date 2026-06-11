#include <iostream>
#include <cstdio>
using namespace std;

int n, k, d, a, ans, v[105];
int main() {
	cin >> n >> k;
	ans = n;
	while(k--) {
		cin >> d;
		while(d--) {
			cin >> a;
			if(!v[a]) v[a] = 1, ans--;
		}
	}
	cout << ans;
	return 0;
}
