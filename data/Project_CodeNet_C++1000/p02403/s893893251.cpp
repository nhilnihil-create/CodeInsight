#include <iostream>
#include <vector>

using namespace std;

struct Rectangle {
	int h;
	int w;
};

int main(void) {
	int a, b;
	vector<struct Rectangle> v;

	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		
		struct Rectangle wk;
		wk.h = a;
		wk.w = b;
		v.push_back(wk);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].h; j++) {
			for (int k = 0; k < v[i].w; k++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}