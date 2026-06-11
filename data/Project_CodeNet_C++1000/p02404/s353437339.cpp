#include<iostream>
using namespace std;	

int main(){
	int H, W;
	while (1){
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (int i = 0; i < H; i++){
			for (int k = 0; k < W; k++){
				if (k > 0 && k < W - 1){
					if (i > 0 && i < H - 1){
						cout << ".";
					}
					else{
						cout << "#";
					}
				}
				else{
					cout << "#";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}