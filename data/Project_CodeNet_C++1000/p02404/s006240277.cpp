#include<iostream>
using namespace std;

void onepri(int x)	//?????????'???'?????¨???????????¢??°
{
	for(int i = 0; i < x; i++)
		cout << '#';
	cout << endl;
}

int main(){
	int H,W;

	while(1){
		cin >> H >> W;
		if(H == 0 && W == 0)break;
		
		onepri(W);

		for(int i = 0; i < H-2; i++){
			for(int j = 0; j < W; j++){
				if(j == 0 || j == W-1)cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
		if(H != 1)onepri(W);

		cout << endl;
	}
	return 0;
}