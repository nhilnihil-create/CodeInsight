
#include <iostream>
using namespace std;


int main(){
	
	int r,c;
	cin >> r >> c;
	int a[r+1][c+1];
	for(int i = 0;i < r;i++){
		int sum = 0;
		for(int j = 0;j < c;j++){
			cin >> a[i][j];
			sum += a[i][j];
		}
		a[i][c] = sum;
	}
	for(int i = 0;i < c+1;i++){
		int sum = 0;
		for(int j = 0;j < r;j++){
			sum += a[j][i];
		}
		a[r][i] = sum;
	}
	
	
	for(int i = 0;i < r+1;i++){
		for(int j = 0;j < c+1;j++){
			cout << a[i][j];
			if(j == c)break;
			cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}