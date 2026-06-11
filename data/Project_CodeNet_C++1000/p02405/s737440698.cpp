#include <iostream>
using namespace std;

int main(){
	int i, j;
	int H = 0;
	int W = 0;

	while (cin >> H >> W){
		if (H != 0 || W != 0){
			for (i = 0; i < H; i++){
				for (j = 0; j < W; j++){
					if ((i + j) % 2 == 0){
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
				cout << "\n";
			}
			cout << "\n";
		}
		else {
			break;
		}
	}
}