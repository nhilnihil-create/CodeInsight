#include <iostream>
using namespace std;

int main(){
	int H, W;
	
	while(true){
		cin >> H >> W;

		if(H == 0 && W == 0) break;

		for(int i = 0; i < H; i++){
			for(int ii = 0; ii < W; ii++){
				if(i % 2 == 1){
					cout << (ii % 2 == 0 ? "." : "#");
				}else{
					cout << (ii % 2 == 0 ? "#" : ".");
				}
			}
			cout << endl;
			
		}

		cout << endl;
	}
	
	return 0;
}