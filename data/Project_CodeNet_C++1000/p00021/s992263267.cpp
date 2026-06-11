#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	float point[4][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> point[j][k];
			}
		}

		if ((point[1][1] - point[0][1]) / (point[1][0] - point[0][0]) == (point[3][1] - point[2][1]) / (point[3][0] - point[2][0]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}