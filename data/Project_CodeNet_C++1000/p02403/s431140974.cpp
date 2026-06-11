#include<iostream>
using namespace std;
int main(){
	while(1){
		int h,w;
		cin >> h >> w;
		if(h == 0 && w == 0){
			break;
		}
		for(int n = 0; n < h; n++){
			for(int m = 0; m < w; m++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}