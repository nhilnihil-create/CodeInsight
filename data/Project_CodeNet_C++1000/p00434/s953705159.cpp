#include <iostream>
using namespace std;

int main() {
	int yj[30] = {};
	int unco[28] = {};
	int a;
	for(int i = 0; i < 30 ; i++){
		yj[i] = i + 1;
	}
	for(int i = 0; i < 28 ; i++){
		cin >> unco[i];
		a = unco[i];
		yj[a - 1] = 0;
	}
	for(int i = 0; i < 30 ; i++){
		if(yj[i] != 0)
			cout << yj[i] << endl;
	}
	return 0;
}