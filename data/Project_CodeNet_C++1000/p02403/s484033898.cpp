#include<iostream>

using namespace std;

int main(void) {

	int i=0, n,h,w,m=-1;
	int H[300], W[300];

	do {

		m = m + 1;
		cin >> H[m] >> W[m];

	} while (H[m] != 0 && W[m] != 0);

	do {

		h = H[i];
		w = W[i];

		if (h == 0 && w == 0) {
			break;
		}

		else {

			for (n = 0; n < h; n++) {

				for (int i = 0; i < w; i++) {

					cout << "#";

				}
				cout << endl;
			}

			cout << endl;

			i++;

		}
	} while (i);

}