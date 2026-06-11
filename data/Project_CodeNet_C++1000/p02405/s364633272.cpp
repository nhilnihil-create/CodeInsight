#include <iostream>
using namespace std;

int main(){
	int H , W;
	int i, j;
	while(1){
		char fig1[301]={0};
		char fig2[301]={0};
		cin >> H >> W;
		if(H==0 && W==0) break;
		for(i=0 ; i<W ; i+=2){
			fig1[i]='#';
		}
		for(i=1 ; i<W ; i+=2){
			fig1[i]='.';
		}
		for(i=0 ; i<W ; i+=2){
			fig2[i]='.';
		}
		for(i=1 ; i<W ; i+=2){
			fig2[i]='#';
		}
		if (H%2==0){
			for(i=0 ; i<H/2 ; i++){
				cout << fig1 << endl;
				cout << fig2 << endl;
			}
		} else {
			for(i=0 ; i<H/2+1 ; i++){
				cout << fig1 << endl;
				if(i!=H/2){
					cout << fig2 << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}