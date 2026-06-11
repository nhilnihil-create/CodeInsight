#include <iostream>
using namespace std;

int main(){
	int H, W, i, j;
	H = 0;
	W = 0;
	while (cin >> H >> W){
		if (H != 0 || W != 0){
			for (i = 0; i < H; i++){
				for (j = 0; j < W; j++){
					cout << "#";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		else {
			break;
		}
	}
	return 0;
}