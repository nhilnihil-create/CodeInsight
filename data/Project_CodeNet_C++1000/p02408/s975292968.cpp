#include<iostream>
using namespace std;

int main(){
	int n, r;
	int card[4][14];
	char M;
	for(int i = 0; i < 4; i++){
		for(int j = 1; j < 14; j++){
			card[i][j] = 0;
		}
	}
	cin >> n;
	for(int m = 0; m < n; m++){
		cin >> M >> r;
		if(M == 'S') card[0][r] = 1;
		if(M == 'H') card[1][r] = 1;
		if(M == 'C') card[2][r] = 1;
		if(M == 'D') card[3][r] = 1;
	}
	for(int i = 0; i < 4; i++){
		for(int j = 1; j < 14; j++){
			if(card[i][j] == 1) continue;
			if(i == 0) M = 'S';
			if(i == 1) M = 'H';
			if(i == 2) M = 'C';
			if(i == 3) M = 'D';
			cout << M << " " << j << endl;
		}
	}
	
	return 0;
}