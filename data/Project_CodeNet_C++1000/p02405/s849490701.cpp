#include <iostream>
using namespace std;

int main()
{
		int H[10000], W[10000], n, i, j, k;
		while (1) {
				cin >> H[n] >> W[n];
				if (H[n]==0 && W[n]==0) break;
				n++;
		}

		for (i=0; i<n; i++) {
				for (j=0; j<H[i]; j++) {
						for (k=0; k<W[i]; k++) {
								if ((j%2==0 && k%2==0) || (j%2==1 && k%2==1)) cout << "#";
								else if ((j%2==0 && k%2==1) || (j%2==1 && k%2==0)) cout << ".";
						}
						cout << "\n";
				}
				cout << "\n";
		}
}