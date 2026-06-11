#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int H, W;
	int i, j;

	

	while (1)
	{
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				if (0 < j && j < W - 1 && 0 < i && i < H - 1) {
					cout << '.';
					continue;
				}
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}

	

	return (0);
}