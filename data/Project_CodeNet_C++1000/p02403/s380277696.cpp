// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
#include <cstring>
#define INF 1000001
typedef long long llong;
using namespace std;



int main() {

	int H, W;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

