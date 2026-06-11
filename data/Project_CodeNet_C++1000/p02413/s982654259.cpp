#include<iostream>

using namespace std;

int main(){
	int n, m, x;
	int h[100][100];
	
	cin >> n >> m;
	
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < m; j++ ){
			cin >> x;
			h[i][j] = x;
		}
	}

	
	for ( int i = 0; i < n; i++ ){
		int sum = 0;
		for (int j = 0; j < m; j++ ){
			sum += h[i][j]; 
			cout << h[i][j] << " ";
		}
		cout << sum <<endl;
	}
	
	int total = 0;
	
	for ( int j = 0; j < m; j++ ){
		int sum = 0;
		for ( int i = 0; i < n; i++ ){
			sum += h[i][j];
		}
		total += sum;
		cout << sum << " ";
	}
	cout << total <<endl;
	
	return 0;
}