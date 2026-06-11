#include <iostream>
using namespace std;

int main(){
	int H, W;
	
	while(true){
		cin >> H >> W;

		if(H == 0 && W == 0) break;

		for(int i = 0; i < H; i++){
			for(int ii = 0; ii < W; ii++){
				if(0 < i && i < H - 1 && 0 < ii && ii < W -1){
					cout << ".";
				}else{
					cout << "#";
				}
			}
			cout << endl;
			
		}

		cout << endl;
	}
	
	return 0;
}