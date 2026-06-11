#include <iostream>
#include <string>
using namespace std;

int main(){
	int W, H;
	string o = "";
	while (true){
		cin >> H >> W;
		if (W == 0 && H == 0){
			break;
		}
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				o += "#";
			}
			o += "\n";
		}
		o += "\n";
	}
	cout << o;
}