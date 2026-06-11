#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void Rect(int h, int w){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << '#';
			if (j==w-1) cout << endl;
		}
	}
}

int main(){
	int H,W;
	
	while(true){
		
		cin >> H >> W;
		if(H==0&&W==0) break;
		Rect(H,W);
		cout << endl;
	}
}