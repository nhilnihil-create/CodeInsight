#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const int M = 100000;
const double pi = 3.141592653589;

int sum(int n, int array[]) {

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum;
}

int main(){
	int n, m, l;
	int a[1000][1000] = { 0 }, b[1000][1000] = { 0 };
	long long c[1000][1000] = { 0 };

	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < l; k++) {
			cin >> b[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < l; k++) {
			for (int p = 0; p < m; p++) {
				c[i][k] += a[i][p] * b[p][k];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < l; k++) {
			cout << c[i][k];
			if (k == l - 1) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}