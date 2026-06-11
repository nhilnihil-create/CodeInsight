#include <iostream>
//#include <stdio.h>
using namespace std;

int main(){
	int H, W;
	char c;
	while(1){
		cin >> H >> W;
		if (H == 0 && W ==0)  break;
		for (int i=0;i < H;i++){
			if (i % 2) c = '.';
			else c = '#';
			for (int j=0; j<W; j++){
				cout << c;
				if ( c == '#') c = '.';
				else c = '#';
				
			}
			cout << endl ;
		}
		cout << endl ;
	}
	return 0;
}