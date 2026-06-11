#include <iostream>
using namespace std;

int main (){
	int H,W;
	while(true){
		cin >> H >>W;
		if(H==0 &&W==0) break;
		for(int i = 0;i<H;++i){
			if(i==0 || i==H-1){
				for(int j=0;j<W;++j){
					cout <<"#";
				};
			}
			else {
				cout<<"#";
				for(int k=1;k<W-1;++k){
					cout <<".";
				};
				cout<<"#";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}