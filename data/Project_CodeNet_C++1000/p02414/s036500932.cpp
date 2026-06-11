#include<iostream>
using namespace std;

int main(){
	int n, m, l;
	cin >> n >> m >> l;

	int a[n+1][m+1] = {};
	int b[m+1][l+1] = {};

	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < m+1; j++){
			cin >> a[i][j];
		}
	}

	for (int i = 1; i < m+1; i++){
		for (int j = 1; j < l+1; j++){
			cin >> b[i][j];
		}
	}

	long long int c[n+1][l+1] = {};
	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < l+1; j++){
			for (int k = 1; k < m+1; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < l+1; j++){
			cout << c[i][j];
			if (j != l) cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
