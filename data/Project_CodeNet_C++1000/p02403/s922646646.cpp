#include <iostream>
using namespace std;

int main() {

	int h, w;

	while (true) {

		cin >> h >> w;

		if (h == 0 && w == 0)break;

		for (int i = 0; i + 1 <= h;i++) {

			for (int j = 0; j + 1 <= w;j++) {

				cout << "#";
			}
			cout << endl;
		}

		cout << endl;

	}

	//cin >> /*変数他*/;
	//cout << /*文字列*/ << endl;
}
