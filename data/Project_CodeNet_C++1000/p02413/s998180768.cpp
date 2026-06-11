#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int r, c;
	cin >> r >> c;
	int spreadsheet[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> spreadsheet[i][j];
		}
	}
	int rsum[r];
	for(int i = 0; i < r; i++){
		rsum[i] = 0;
	}
	int csum[c];
	for(int i = 0; i < c; i++){
		csum[i] = 0;
	}
	int totalsum = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			rsum[i] += spreadsheet[i][j];
			totalsum += spreadsheet[i][j];
		}
	}
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			csum[i] += spreadsheet[j][i];
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << spreadsheet[i][j] << " ";
		}
		cout << rsum[i] << "\n";
	}
	for(int i = 0; i < c; i++){
		cout << csum[i] << " ";
	}
	cout << totalsum << "\n";
}
