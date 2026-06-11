#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main() {

	ll H, W;
	cin >> H >> W;
	if(H == 1){
		cout << 1 << endl;
		return 0;
	}
	if (W == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (W % 2 == 0 && H % 2 == 0) {
		cout << W * H / 2 << endl;
	}
	else if(W % 2 == 0 && H % 2 == 1){
		cout << W * H / 2 << endl;
	}
	else if (W % 2 == 1 && H % 2 == 0) {
		cout << W * H / 2 << endl;
	}
	else {
		cout << (W / 2) * (H / 2) + (W / 2 + 1) * (H / 2 + 1) << endl;
	}
	return 0;
}