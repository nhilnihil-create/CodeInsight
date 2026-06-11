#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long int lint;

void answer()
{
	int H, W;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << ((i == 0 || i == H - 1 || j == 0 || j == W - 1) ? '#' : '.');
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	answer();
	return 0;
}