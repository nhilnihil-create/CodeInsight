#include<iostream>
using namespace std;
int main(){
	for (;;){
		int H;
		int W;
		cin >> H >> W;
		if (H == 0 && W == 0){
			return 0;
		}
		else{
			for (int a = 0; a < H; a++){
				for (int b = 0; b < W; b++){
					cout << "#";
				}
				cout << endl;
			}
		}cout << endl;
	}
}