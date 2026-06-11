#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	rep(i, n + 1) {
		if (i % 3 != 0 && i % 5 != 0) {
			ans += i;
		}
	}
	cout << ans << endl;
}