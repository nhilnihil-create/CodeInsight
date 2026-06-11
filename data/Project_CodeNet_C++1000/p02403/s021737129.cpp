#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void print_rec(int h, int w){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << "#";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void){

	int h,w;
	while(1){
		cin >> h >> w;
		if(h == 0 && w == 0) break;
		print_rec(h, w);
	}
	return 0;
}