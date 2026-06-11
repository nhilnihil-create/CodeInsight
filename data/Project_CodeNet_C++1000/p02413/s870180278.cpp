#include <iostream>
using namespace std;

int main(){
	int r,c,n,count=0,total=0;
	cin >> r >> c;
	int x[r+1][c+1]={};
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> n;
			x[i][j]=n;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			count+= x[i][j];
		}
		x[i][c] = count;
		total += count;
		count=0;
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			count += x[j][i];
		}
		x[r][i]=count;
		count=0;
	}
	x[r][c]=total;
	
	for(int i=0;i<(r+1);i++){
		for(int j=0;j<c;j++){
			cout << x[i][j] << ' ';
		}
		cout << x[i][c] << endl;
	}
	return 0;
}