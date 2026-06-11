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
			for(int ii=1 ;ii<=H; ii++){
				for(int iii=1 ;iii<=W; iii++){
					if(ii==H || ii==1 || iii==W || iii==1){
						cout << "#";
					}else{
						cout << ".";
					}
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}