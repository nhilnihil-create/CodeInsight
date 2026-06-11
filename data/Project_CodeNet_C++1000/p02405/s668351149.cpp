#include<iostream>

using namespace std;

int main(void) {

	int i = 0, n, h, w, m = -1,j=0,l=0;
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

				j = 0;

				for (int i = j+l; i < w+l; i++) {

					if (i % 2 == 0)
						cout << "#";

					else if (i % 2 == 1)
						cout << ".";

				}
				cout << endl;
				l = l + 1;
			}

			cout << endl;

			i++;
			l = 0;

		}
	} while (i);

}