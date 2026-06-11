#include<iostream>
using namespace std;
int main(){
	int H,W;
	

		
		while (1){
			cin >> W >> H;
			if (H == 0 && W == 0)break;
			for (int a = 0; a < W; a++){
				for (int a = 0; a < H; a++){
					cout << "#";
				}
				cout << endl;
			}
			cout << endl;
		}
	

	return 0;
}