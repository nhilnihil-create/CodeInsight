#include <iostream>
using namespace std;

int main(){
	int i, j;
	//int n;
	int H = 0;
	int W = 0;

	//for (n = 0; n < 1; n++){
	while (cin >> H >> W){
		//H = 6;
		//W = 5;
		if (H == 0 && W == 0){
			break;
		}
		else {
			for (i = 0; i < H; i++){
				if (i == 0 || i == H-1){
					for (j = 0; j < W; j++){
						cout << "#";
					}
					cout << "\n";
				}
				else {
					for (j = 0; j < W; j++){
						if (j == 0 || j == W-1){
							cout << "#";
						}
						else {
							cout << ".";
						}
					}
					cout << "\n";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}