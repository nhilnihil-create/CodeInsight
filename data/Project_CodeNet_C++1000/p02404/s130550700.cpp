#include<iostream>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	while (H != 0 && W != 0) {
		for (int i = 0; i < W; i++)
			cout << "#";
		cout << endl;
		for (int j = 0; j < H - 2; j++) {
			cout << "#";
			for (int k = 0; k < W - 2; k++) {
				cout << ".";
			}
			cout << "#" << endl;
		}
		for (int l = 0; l < W; l++)
			cout << "#";
		cout << endl;
		cout << endl;
		cin >> H >> W;
	}
}
