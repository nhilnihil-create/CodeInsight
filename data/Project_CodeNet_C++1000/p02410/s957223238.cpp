#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[110][110];
	int c[110] = { 0 };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		int k; cin >> k;
		for (int j = 0; j < n; j++){
			a[j][i] *= k;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			c[i] += a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		cout << c[i] << endl;
	}
	return 0;
}