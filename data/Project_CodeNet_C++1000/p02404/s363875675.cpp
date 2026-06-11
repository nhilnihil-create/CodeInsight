#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	while (cin >> H >> W, H || W) {
		for (int i = 0; i < H; i++) {
			cout << '#';
			for (int j = 1; j + 1 < W; j++) {
				cout << (i > 0 && i + 1 < H ? '.' : '#');
			}
			if(W != 1) cout << '#' << endl;
			else cout << endl;
		}
		cout << endl;
	}
	return 0;
}