#include <iostream>
using namespace std;

int main(int argc,char *argv[]){
	int H,W;
	int count;
	while(1) {
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		for(int i = 0; i < H; i++){
			count = i % 2;
			for (int j = 0; j < W; j++){			
				if (count++ % 2 == 0){
					cout << "#";
				} else {
					cout << ".";
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}