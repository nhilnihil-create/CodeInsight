#include<iostream>
using namespace std;
int main()
{
	int r, c,a[101],b[100],d=0;
	int h[101][101]={0};
	cin >> r >> c;
	for (int i=0; i < r;i++){
		for (int j=0; j < c; j++){
			cin >> h[i][j];
		}
	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			h[i][c] += h[i][j];
		}
	}
	
	for (int j = 0; j <= c; j++){
		for (int i = 0; i < r; i++){
			h[r][j] += h[i][j];
		}
	}
	for (int i = 0; i < r+1; i++){
		for (int j = 0; j < c+1; j++){
			if (d) cout << " "; 
			cout << h[i][j];
			d = 1;
		}
		d = 0;
		cout << endl;
	}
	return 0;
}