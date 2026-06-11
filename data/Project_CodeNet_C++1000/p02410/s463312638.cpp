#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int b[m+1] = {};
	int a[n+1][m+1] = {};

	for (int j = 1; j < n + 1; j++){
		for (int h = 1; h < m + 1; h++){
			cin >> a[j][h];
		}
	}

	for (int i = 1; i < m + 1; i++){
		cin >> b[i];
	}

	int c[n+1] = {};
	for (int k = 1; k < n+1; k++){
		for (int l = 1; l < m+1; l++){
			c[k] += a[k][l] * b[l];
		}
	}

	for (int p = 1; p < n+1; p++){
		cout << c[p] << "\n";
	}

	return 0;
}
