#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int H, W;
	while (true) {
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++)
				if ((w + h) % 2)
					cout << ".";
				else
					cout << "#";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}