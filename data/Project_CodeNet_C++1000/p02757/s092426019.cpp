#include <iostream>
using namespace std;

int main() {
	long long n, p;
	string s;
	cin >> n >> p >> s;
	long long ans = 0;
	if (p == 2 || p == 5) {
		for (int i = 0; i < n; i++) {
			if ((s[i]-'0')%p==0) ans += i+1;
		}
	} else {
		int a[10000] = {1};
		int z = 1;
		int x = 0;
		for (int i = n-1; i >= 0; i--) {
			x += z * (s[i]-'0') % p;
			x %= p;
			ans += a[x];
			a[x]++;
			z = z*10%p;
		}
	}
	cout << ans << endl;
	return 0;
}