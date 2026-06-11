#include <iostream>
using namespace std;

int main(){
	int H[10000], W[10000];
	int ct = 0;
	while(true){
		cin >> H[ct] >> W[ct];
		if(H[ct] == 0 && W[ct] == 0) break;
		ct++;
	}
	for(int h = 0; h <= ct; h++){
		if(h != 0) cout << endl;
		for(int i = 0; i < H[h]; i++){
			if(i == 0 || i == H[h] - 1){
				for(int j = 0; j < W[h]; j++){
					cout << '#';
				}
			}
			else{
				cout << '#';
				for(int j = 1; j < W[h] - 1; j++){
					cout << '.';
				}
				cout << '#';
			}
			cout << endl;
		}
	}
}