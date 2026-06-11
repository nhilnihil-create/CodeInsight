#include<iostream>
using namespace std;
int main() {
	long long a, b, n, ans; cin >> a >> b >> n;
	ans = a * (b - 1) / b - a * ((b - 1) / b);
	if (n < b) {
		ans = a * n / b - a * (n / b);
	}
	cout << ans << endl;
}