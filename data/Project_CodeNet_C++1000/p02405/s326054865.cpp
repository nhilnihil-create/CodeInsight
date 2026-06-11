#include<iostream>
using namespace std;

	int main() {
		int H, M;
		for (;;) {
			cin >> H >> M;
			if (H == 0 && M == 0)break;
			for (int i = 0; i < H; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < M; j++) {
						if (j % 2 == 0) { cout << "#"; }
						else { cout << "."; }
					}
				}
				else {
					for (int j = 0; j < M; j++) {
						if (j % 2 == 0) { cout << "."; }
						else { cout << "#"; }
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		return 0;
	}