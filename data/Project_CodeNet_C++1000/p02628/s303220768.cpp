#include <iostream>
using namespace std;
int main()
{
	int n, m, x[1000], k = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int a = 0; a < n - 1; a++) {
		for (int b = 0; b < n - a - 1; b++) {
			if (x[b] > x[b + 1]) {
				swap(x[b], x[b + 1]);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		k += x[j];
	}
	cout << k;
}