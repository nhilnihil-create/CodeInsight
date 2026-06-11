#include<iostream>
using namespace std;

int main(){
	int n, m, l;
	cin >> n >> m >> l;
	int a[101][101], b[101][101];
	long int c[101][101] = {0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int j = 0; j < m; j++){
		for(int k = 0; k < l; k++){
			cin >> b[j][k];
		}
	}
	for(int i = 0; i < n; i++){
		for(int k = 0; k < l; k++){
			for(int j = 0; j < m; j++) c[i][k] += a[i][j] * b[j][k];
		}
		for(int k = 0; k < l-1; k++) cout << c[i][k] << ' ';
		cout << c[i][l-1] << endl;
	}
	return 0;
}