#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
using namespace std;
int  v[102][101], n;
int main() {
	int u, k, s;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			v[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> u;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> s;
			v[u][s] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > 1) cout << " ";
			cout << v[i][j];
		}
		cout << endl;
	}	return 0;
}