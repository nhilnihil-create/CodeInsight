#include <iostream>
using namespace std;

int main(void) {
	int L, R, d;
	cin >> L >> R >> d;

	int ans = (R / d) - ((L - 1) / d);

	cout << ans << '\n';
	return 0;
}
