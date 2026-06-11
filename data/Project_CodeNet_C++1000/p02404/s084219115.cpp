#include<iostream>
using namespace std;

int main(){
	int H,W;

	while(1){
		cin >>H>>W;
		if (W==0 && H==0) break;
		for (int i=1; i<=H; i++){
			
			for (int k=1; k<=W; k++){
				if (i==1 || i==H || k==1 || k==W) cout <<"#";
				else cout << ".";
			}
			cout <<"\n";
		}
		cout << "\n";
	}
	
	return 0;
}