#include <iostream>
using namespace std;

int main()
{
		int H[10000], W[10000], n, i, j, k, m;
		while (1) {
				cin >> H[n] >> W[n];
				if (H[n]==0 && W[n]==0) break;
				n++;
		}

		for (i=0; i<n; i++) {
				for (j=0; j<H[i]; j++) {
						if (j==0 || j==H[i]-1) {
								for (k=0; k<W[i]; k++) {
										cout << "#";
								}
						} else {
								cout << "#";
								for (k=1; k<W[i]-1; k++) {
										cout << ".";
								}
								cout << "#";
						}
						cout << "\n";
				}
				cout << "\n";
		}
}