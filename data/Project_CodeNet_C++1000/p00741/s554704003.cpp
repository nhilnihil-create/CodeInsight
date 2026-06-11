#include <iostream>
using namespace std;
int a[52][52];
int sima(int i,int j,int k){
	if(a[i-1][j-1] == 1){
		a[i-1][j-1] = k;
		sima(i-1,j-1,k);
	}
	if(a[i-1][j] == 1){
		a[i-1][j] = k;
		sima(i-1,j,k);
	}
	if(a[i-1][j+1] == 1){
		a[i-1][j+1] = k;
		sima(i-1,j+1,k);
	}
	if(a[i][j-1] == 1){
		a[i][j-1] = k;
		sima(i,j-1,k);
	}
	if(a[i][j+1] == 1){
		a[i][j+1] = k;
		sima(i,j+1,k);
	}
	if(a[i+1][j-1] == 1){
		a[i+1][j-1] = k;
		sima(i+1,j-1,k);
	}
	if(a[i+1][j] == 1){
		a[i+1][j] = k;
		sima(i+1,j,k);
	}
	if(a[i+1][j+1] == 1){
		a[i+1][j+1] = k;
		sima(i+1,j+1,k);
	}
}

int main() {
	int w,h,k;
	while(1){
		for(int i = 0;i < 52;i++){
			for(int j = 0;j < 52;j++){
				a[i][j] = 0;
			}
		}
		cin >> w >> h;
		if(w == 0)break;
		for(int i = 1;i <= h;i++){
			for(int j = 1;j <= w;j++){
				cin >> a[i][j];
			}
		}
		k = 2;
		for(int i = 1;i <= h;i++){
			for(int j = 1;j <= w;j++){
				if(a[i][j] == 1){
					sima(i,j,k);
					k++;
				}
			}
		}
		cout << k-2 <<endl;
	}
	return 0;
}