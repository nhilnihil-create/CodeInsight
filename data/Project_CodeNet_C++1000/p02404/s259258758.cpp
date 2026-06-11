#include <iostream>
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int H, W;
	while (true) {
		cin >> H >> W;
		if (H == 0 & W == 0)return 0;
		for (int i = 0;i < H;i++) {
			for (int j = 0; j < W;j++) {
				if (i == 0 | i == H - 1) { cout << "#"; continue; }
				if (j == 0 | j == W - 1) { cout << "#"; continue; }
				cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
}