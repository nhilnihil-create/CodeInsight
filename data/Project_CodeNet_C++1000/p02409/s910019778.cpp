#include <iostream>
using namespace std;

int main()
{
	int room = 10;
	int flr = 3;
	int building = 4;

	int n;
	cin >> n;

	int redidents[building][flr][room];
	int i, j, k;
	for (i = 0; i < building; i++)
		for (j = 0; j < flr; j++)
			for (k = 0; k < room; k++)
				redidents[i][j][k] = 0;

	int b, f, r, v;
	for (i = 0; i < n; i++){
		cin >> b >> f >> r >> v;
		redidents[b-1][f-1][r-1] += v;
	}

	for (i = 0; i < building; i++) {
		for (j = 0; j < flr; j++) {
			for (k = 0; k < room; k++) {
				cout << " ";
				cout << redidents[i][j][k];
			}
			cout << "\n";
		}
		int l;
		if (i != building-1) {
			for (l = 0; l < 2*room; l++) cout << "#";
			cout << "\n";
		}
	}

	return 0;
}