#include <iostream>
using namespace std;

int main(void) {
	int H1, M1, H2, M2, K;
	cin >> H1 >> M1 >> H2 >> M2 >> K;

	int ans = (H2 * 60 + M2) - (H1 * 60 + M1) - K;

	cout << ans << '\n';
	return 0;
}
