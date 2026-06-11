#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int H, W;
	for(int i=0 ; ; i++){
		cin >> H >> W;
		if(H==0 && W==0){
			break;
		}else{
			for(int ii=0 ;ii<H; ii++){
				for(int iii=0 ;iii<W; iii++){
					cout << "#";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}