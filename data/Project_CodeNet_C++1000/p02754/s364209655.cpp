#include<iostream>
using namespace std;

int main() {
	long long n, a, b, ans = 0; cin >> n >> a >> b;
	ans = n / (a + b) * a;
	long long tmp = n % (a + b);
	if (tmp) {
		ans += (tmp >= a ? a : tmp);
	}
	cout << ans << endl;

	return 0;
}