#include <iostream>

using namespace std;

bool is_frame(int H, int W, int x, int y){
	if(x == 1 || x == W) return true;
	if(y == 1 || y == H) return true;
	return false;
}

int main(){
	int H, W;

	while(true){
		cin >> H >> W;
		if(H == 0 && W == 0) break;
		for(int y = 1; y <= H; y++){
			for(int x = 1; x <= W; x++){
				if(is_frame(H, W, x, y)) cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}