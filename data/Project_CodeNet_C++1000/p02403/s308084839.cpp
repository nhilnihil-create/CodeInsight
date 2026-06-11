#include <iostream>
#include <string>
using namespace std;
int main() {
	int H, W, i;
	string row, output;
	while (true) {
		row = "";
		output = "";
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (i = 0; i < W; i++) row += '#';
		row += '\n';
		for (i = 0; i < H; i++)output += row;
		cout << output << endl;
	}
}