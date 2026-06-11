#include <iostream>
using namespace std;
  
int main() {

    int H, W;
    cin >> H >> W;
    
	while (1) {
		if ((H == 0)&&(W == 0)) break;
		for (int h = 1; h <= H; h++) {
	   	 	for (int w = 1; w <= W; w++) {
	    		cout << "#";
			}
			cout << endl;
		}
	cout << endl;
	cin >> H >> W;
	}

    return 0;
}
