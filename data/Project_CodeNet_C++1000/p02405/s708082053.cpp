#include<iostream>
using namespace std;	

int main(){
	int H, W;
	while (1){
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (int i = 0; i < H; i++){
			for (int k = 0; k < W; k++){
				if (i % 2 == 1){
					if (k % 2 == 1){
						cout << "#";
					}
					else{
						cout << ".";
					}
				}
				else{
					if (k % 2 == 1){
						cout << ".";
					}
					else{
						cout << "#";
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}