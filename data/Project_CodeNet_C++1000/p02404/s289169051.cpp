#include <iostream>
#include <string>
using namespace std;
int main() {
	int H, W, i;
	string topAndBottom, middleRow, middle;
	while (true) {
		topAndBottom = "";
		middleRow = "";
		middle = "";
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (i = 0; i < W; i++)topAndBottom += '#';
		topAndBottom += '\n';
		middleRow += '#';
		for (i = 1; i < W - 1; i++)middleRow += '.';
		middleRow += "#\n";
		for (i = 1; i < H - 1; i++)middle += middleRow;
		cout << topAndBottom << middle << topAndBottom << endl;
	}
}