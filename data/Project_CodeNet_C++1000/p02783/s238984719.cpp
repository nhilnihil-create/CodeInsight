#include <iostream>
using namespace std;
int main() {
	int h, a;
	int ans = 0;
	cin >> h >> a;
	do {
		h -= a;
		ans++;
	} while (h > 0);
	cout << ans << "\n";
}