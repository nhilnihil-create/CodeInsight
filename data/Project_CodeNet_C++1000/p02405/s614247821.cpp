#include<iostream>
using namespace std;

int main(){

	int H, W;

	cin >> H >> W;

	while( H != 0 && W != 0){			//W=0とH=0になるまで繰り返す
		for(int i = 1; i <= H; i++){		//縦軸に[＊]を増やして行く
			for(int j = 1; j <= W; j++){	//横軸に[＊]を増やして行く
				cout << ".#"[(i+j)%2 == 0];	// [#]のマークがあるときの条件を　[ この中に条件を入れる ]　
			}
			cout << endl ;
		}
		cout << endl;
		cin >> H >> W;
	}

	return 0;
}
