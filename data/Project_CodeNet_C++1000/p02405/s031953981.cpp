#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

	int H,W,i,j;

	while(1){
		cin >> H >> W;

		if((H==0)&&(W==0))break;
		else{
			for(i=1;i<=H;i++){
				for(j=1;j<=W;j++){
					if(((j%2==1)&&(i%2==1))||((j%2==0)&&(i%2==0)))cout << "#";
					else cout << ".";
				}cout << endl;
			}cout << endl;

			
		}

	}		
	return 0;
}