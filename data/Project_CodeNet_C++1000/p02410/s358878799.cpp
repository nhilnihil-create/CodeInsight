#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int A[n][m];
	int b[m][1];
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x;
			cin >> x;
			A[i][j] = x;
		}
	}
	
	for (int i = 0; i < m; i++){
		int y;
		cin >> y;
		b[i][1] = y;
	}

	for (int i = 0; i < n; i++){
		int ans = 0;
		for(int j = 0; j < m; j++){
			ans += A[i][j] * b[j][1];
		}
		cout << ans << endl;
	}
	return 0;
}