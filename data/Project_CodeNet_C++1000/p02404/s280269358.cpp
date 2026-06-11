#include <iostream>
using namespace std;
int main(){
	for(;;){
		int H,W,i,l;
		cin >> H >> W;
		if(H==0 && W==0)break;

		for(i=0; i<H; i++){
			for(l=0; l<W; l++){
				if(l==0 || l==W-1 || i==0 || i==H-1){
					cout << "#";
				} else {
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;	
	}
}