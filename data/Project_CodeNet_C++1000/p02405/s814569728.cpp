#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int H,W;
	int i,j;

	while (1) {
		cin >> H;
		cin >> W;

		if ((H==0) && (W==0)) {
			break;
		}

		for (i = 0; i < H; i++) {
			for ( j = 0; j < W; j++) {
				if ((i%2) == 0) {
					if ((j%2) == 0) {
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
				else {
					if ((j%2) == 0) {
						cout << ".";
					}
					else {
						cout << "#";
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

