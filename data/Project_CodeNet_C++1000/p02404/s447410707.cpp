#include<iostream>
using namespace std;

int main(){

	int H, W;

	cin >> H >> W;

	while( H != 0 && W != 0){					//W=0とH=0になるまで繰り返す
		for(int i = 0; i < H; i++){				//縦軸に[＊]を増やして行く
			for(int j = 0; j < W; j++){			//横軸に[＊]を増やして行く
				cout << ".#"[j==0 || j == W-1 || i == 0 || i == H-1];
			}
			cout << endl ;
		}
		cout << endl;
		cin >> H >> W;
	}

	return 0;
}
