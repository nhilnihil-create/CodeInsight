#include <iostream>
using namespace std;

int f(int H, int W){
	int a=W;
	while(H){
		while(W){
			printf("#");
			W--;
		}
		cout << endl;
		W=a;
		H--;
	}
}

int main() {
	int H, W;
	while(cin >> H >> W){
		if(H==0&&W==0){break;}
		f(H, W);
		cout << endl;
	}
	return 0;
}