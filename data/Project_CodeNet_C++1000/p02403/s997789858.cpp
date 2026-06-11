#include <iostream>
using namespace std;

int main() {
	int h,w;
	
	for(;;){
		cin >> h >> w;
		if(h>0 && w>0){
			for(int i=0; i<h; i++){
				for(int j=0; j<w; j++){
					cout << "#";
					if(j+1==w){
						cout << endl;
					}
				}
				if(i+1==h){
					cout << endl;
				}
			}
		}else if(h==0 && w==0){
			break;
		}
	}
	return 0;
	
}