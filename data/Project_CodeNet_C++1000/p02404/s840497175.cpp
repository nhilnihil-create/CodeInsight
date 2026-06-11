#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int H,W;
	while(1){
		cin >> H >> W ;
		if(H==0&&W==0)return 0;
		for(int i=0;i<W;i++){
			cout << "#" ;
		}
		cout << endl;
		for(int i=0;i<H-2;i++){
			cout << "#" ;
			for(int i=0;i<W-2;i++){
				cout << "." ;
			}
			cout << "#" << endl ;
		}
		for(int i=0;i<W;i++){
			cout << "#" ;
		}
		cout << endl << endl;
	}
	return 0;
}