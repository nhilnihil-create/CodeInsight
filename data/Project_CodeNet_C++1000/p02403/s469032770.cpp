#include <iostream>
using namespace std;
int main() {
	int H, W;
	cin>> H >> W;
	while (W>0 && H>0){
		for (int i=1; i<=H; i++ ) {
			for (int j=1; j<=W; j++ ) {
				cout<< "#";
			}
			cout<<endl;
		}cout<<endl;
		cin>> H >> W;
	}
	
	return 0;
}
