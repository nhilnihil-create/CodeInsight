#include <iostream>
#include <cstdio>
using namespace std;

long long n, d, x, y, ans;
int main() {
	cin >> n >> d;
	while(n--) {
		scanf("%lld%lld", &x, &y);
		if(x*x + y*y <= d*d) ans++;
	}
	cout << ans;
	return 0;
}
