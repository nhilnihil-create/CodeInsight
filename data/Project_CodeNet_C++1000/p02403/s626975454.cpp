#include<iostream>

using namespace std;

int main() {

	int H,W;
	int i,n,m;

	while (1) {

                cin>>H>>W;

		if (H == 0 && W == 0) break;

		for (n = 0; n < H; n++) {

			for (m = 0; m < W; m++) {
				cout << "#";
			}

			cout << endl;

		}

		cout << endl;

	}
	return 0;
}