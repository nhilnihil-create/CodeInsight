#include <iostream>
using namespace std;

void print_rectangle(int H, int W);

int main() {
	int H, W;
	while(cin >> H >> W){
		if (H == 0 && W == 0) break;
		print_rectangle(H, W);
	}
}

void print_rectangle(int H, int W){
	for (int h=0; h != H; ++h){
		for (int w=0; w != W; ++w){
			cout << '#';
		}
		cout << endl;
	}
	cout << endl;
}