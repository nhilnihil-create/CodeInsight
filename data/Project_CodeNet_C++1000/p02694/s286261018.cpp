#include<iostream>
using namespace std;
int main() {
	long long ans = 0, n = 100, x; cin >> x;
	while (true) {
		ans++;
		n += n/100;
		if (n >= x) {
			cout << ans << endl;
			break;
		}
	}
}
