#include<iostream>

using namespace std;

int main(){
	int h,w;
	while(cin >> h >> w){
		if(h == 0 && w == 0){
			break;
		}
		for(int i = 0; i < h; i++){
			if(i % 2 == 0){
				for(int j = 0; j < w / 2; j++){
					cout << "#.";
				}
				if(w % 2 == 1){
					cout << "#";
				}
			}
			if(i % 2 == 1){
				for(int j = 0; j < w / 2; j++){
					cout << ".#";
				}
				if(w % 2 == 1){
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}