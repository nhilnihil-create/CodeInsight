#include <iostream>
#include <string>
using namespace std;
int main() {
	int H, W, i;
	char c;
	string row;
	while (true) {
		row = "";
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		else if (W % 2 == 0)c = '.';
		else c = '#';
		for (i = 0; i < W-1; i++) {
			if (i % 2 == 0)row += '#';
			else row += '.';
		}
		for (i = 0; i < H;i ++) {
			if (i % 2 == 0)cout << row << c << endl;
			else cout << '.' << row << endl;
		}
		cout << endl;
	}
}