#include<iostream>
using namespace std;

int main() {
	int H, M;
	for (;;) {
		cin >> H >> M;
		if (H == 0 && M == 0)break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < M; j ++ ) {
				if (i == 0 ||i == (H-1)) { cout << "#"; }
				else if (j==0||j == (M-1)) { cout << "#"; }
				else { cout << "."; }
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}