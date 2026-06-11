#include <iostream>
using namespace std;

int main() {
	int H, W;

	while (1) {
		cin >> H >> W;

		if (!H && !W)
			break;

		for (int r = 1; r <= H; r++)
		{
			for (int c = 1; c <= W; c++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
			
	}

	return 0;
}