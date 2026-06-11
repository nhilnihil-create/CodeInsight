#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int H,W,i,j;
	while(1){
		cin>> H>> W;
		if(H==0 && W==0){
			break;
		}
		for(i=0;i<W;i++){
			cout<< "#";
		}
		cout<< endl;
		for(i=0;i<H-2;i++){
			cout<< "#";
			for(j=0;j<W-2;j++){
				cout<< ".";
			}
			cout<< "#"<<endl;
		}
		if(H>1){
			for(i=0;i<W;i++){
				cout<< "#";
			}
			cout<< endl;
		}
		cout<<endl;
	}
	return 0;
}