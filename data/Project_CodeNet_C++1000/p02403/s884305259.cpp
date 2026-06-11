#include <iostream>
using namespace std;
int  main(){

	int H, W;

	for (;;){

		cin >> H >> W;
		if (H == 0 && W == 0)break;

		for (int q = 0;q != H;q++){

			for (int p = 0; p != W; p++){
				cout << "#";

			}
			cout << endl ;
		}cout << endl;
	}
	return 0;
}