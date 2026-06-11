#include <iostream>
using namespace std;

void print_frame(int H, int W);
void print_bread(int W);
void print_meat(int W);

int main() {
	int H, W;
	while(cin >> H >> W){
		if (H == 0 && W == 0) break;
		print_frame(H, W);
	}
}

void print_frame(int H, int W){
	print_bread(W);
	for (int h=2; h != H; ++h){
		print_meat(W);
	}
	print_bread(W);
	cout << endl;
}

void print_bread(int W){
	for (int w=0; w != W; ++w){
			cout << '#';
	}
	cout << endl;
}

void print_meat(int W){
	cout << '#';
	for (int w=2; w != W; ++w){
		cout << '.';
	}
	cout << '#' << endl;
}