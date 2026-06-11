#include<iostream>
using namespace std;

int main(){
	int H,W;

	while(1){
		cin >>H>>W;
		if (W==0 && H==0) break;
		for (int i=1; i<=H; i++){
			for (int k=1; k<=W; k++)cout << "#";
			cout <<"\n";
		}
		cout << "\n";
	}
	
	return 0;
}