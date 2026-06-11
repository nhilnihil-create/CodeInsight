#include<iostream>
#include<set>
using namespace std;

int main() {
	int K;
	cin >> K;

	int ans = 1;
	int x = 7 % K;
	set<int> mod;
	while (mod.count(x) == 0) {
		mod.insert(x);
		if (x == 0) {
			cout << ans << endl;
			return 0;
		}
		else {
			x = (10 * x + 7) % K;
			ans++;
		}
	}
	cout << -1 << endl;
	return 0;
}