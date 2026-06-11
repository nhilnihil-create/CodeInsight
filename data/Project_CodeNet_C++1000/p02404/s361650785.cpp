#include<iostream>
using namespace std;
int main(){
	int H;
	int W;
	for (;;){
		cin >> H >> W;
		if (H == 0 && W == 0){
			return 0;
		}else{
			for (int b = 0; b < H; b++){
				for (int c = 0; c < W; c++){
					if (c == 0){
						cout << "#";
					}
					else if (c == W-1){
						cout << "#";
					}
					else if (b == 0){
						cout << "#";
					}
					else if (b == H-1){
						cout << "#";
					}else{
						cout << ".";
					}
				}cout << endl;
			}cout << endl;
		}

	}
}