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
		for(i=0 ; i<W ; i++){
			fig1[i]='#';
		}
		fig2[0]='#';
		fig2[W-1]='#';
		for(i=1 ; i<W-1 ; i++){
			fig2[i]='.';
		}
		cout << fig1 << endl;
		for(i=0 ; i<H-2 ; i++){
			cout << fig2 << endl;
		}
		cout << fig1 << endl;
		cout << endl;
	}
	return 0;
}