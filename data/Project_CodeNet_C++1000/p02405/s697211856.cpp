#include <iostream>
using namespace std;

int main(){
	int H[1000], W[1000];
	int ct = 0;
	while(true){
		cin >> H[ct] >> W[ct];
		if(H[ct] == 0 && W[ct] == 0) break;
		ct++;
	}
	for(int h = 0; h <= ct; h++){
		if(h != 0) cout << endl;
		for(int i = 0; i < H[h]; i++){
			for(int j = 0; j < W[h]; j++){
				if((i + j) % 2 == 0) cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
	}
}