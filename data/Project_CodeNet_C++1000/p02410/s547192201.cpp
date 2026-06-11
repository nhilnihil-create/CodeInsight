#include <iostream>
#define N 100
#define M 100
using namespace std;
main () {
	int n, m, a[N][M], b[M], c[M] = {};
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) cin >> a[i][j];
	for (int j=0; j<m; j++) cin >> b[j];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) c[i] += a[i][j] * b[j];

	for (int j=0; j<n; j++) cout << c[j] << endl;
}