#include <iostream>
using namespace std;
int main(){
	int i,l,H,W;
	for(;;){
		cin >> H >> W;
		if(H==0 && W ==0)return 0;
		for(i=0; i<H; i++){
				for(l=0; l<W; l++){
					//???????????????????????????????????????
					if(i==0 || i==H-1)
					{
						cout << "#";
					}
					//
					else if (i!=0 || i!=H-1)
					{
						if(l==0 || l==W-1){
							cout << "#";
						}
						else if(l!=0|| l!=W-1){
							cout << ".";
					}
				}		
			}	
			cout << endl;
		}
	cout << endl;
	}
	return 0;

}