#include <iostream>
#define M 100
#define N 100
using namespace std;

int main()
{
	int ary[N][M];
	int n, m;
	int i, j;
	int *c;
	int sum = 0;

	cin >> n >> m;

	c = new int[m];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> ary[i][j];
		}
	}

	for (j = 0; j < m; j++) {
		cin >> c[j];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			sum += ary[i][j] * c[j];
		}
		cout << sum << endl;
		sum = 0;
	}

	delete [] c;

	return 0;
}