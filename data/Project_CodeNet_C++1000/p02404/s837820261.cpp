#include <iostream>
using namespace std;

int main(){
	int H = 1;
	int W = 1;

	cin >> H >> W;
	while(H != 0 & W != 0){
		for(int h=0; h<H; h++){
			for(int w=0; w<W; w++){
				if(h == 0 | h == H-1) {cout << "#";}
				else{
					if(w == 0 | w == W-1) {cout << "#";}
					else {cout << ".";}
				}
			}
			cout << "" << endl;
		}
		cout << "" << endl;
		cin >> H >> W;
	}

	return 0;
}