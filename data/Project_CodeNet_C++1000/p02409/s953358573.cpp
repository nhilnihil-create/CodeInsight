#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{		
	int n;
	int house[4][3][10] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;
		house[b-1][f-1][r-1] += v;
	}
	
	for (int b = 0; b < 4; b++) {
		for (int f = 0; f < 3; f++) {
			for (int r = 0; r < 10; r++) {
				cout << " " << house[b][f][r];
			}
			cout << "\n";
		}
		if (b < 3) {
			cout << "####################\n";
		}
	}
	
	return 0;
}