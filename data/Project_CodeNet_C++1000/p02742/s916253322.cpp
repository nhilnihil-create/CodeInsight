#include<iostream>
using namespace std;
int main() {
	long long int H, W;
	cin >> H >> W;
	long long int ans = 0;
	if (H * W % 2 == 0) {
		ans = H * W / 2;
	}
	else {
		ans = H * W / 2 + 1;
	}
	if (H == 1 || W == 1) {
		ans = 1;
	}
	cout << ans << endl;
	return 0;
}