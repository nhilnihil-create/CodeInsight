#include<iostream>
using namespace std;
int main(){
	int H;
	int W;
	for (;;){
		cin >> H >> W;
		if (H == 0 && W == 0){
			return 0;
		}else{for (int b = 0; b < H; b++){
				if (b % 2 == 0){
					for (int c = 0; c < W; c++){
						if (c % 2 == 0){
							cout << "#";
						}else{
							cout << ".";
						}
					}cout << endl;
				}else{
					for (int c = 0; c < W; c++){
						if (c % 2 == 0){
							cout << ".";
						}
						else{
							cout << "#";
						}
					}cout << endl;
				}
			}cout << endl;
		}

	}
}