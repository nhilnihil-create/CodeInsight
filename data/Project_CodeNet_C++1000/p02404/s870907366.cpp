#include <iostream>
#include <vector>

using namespace std;

struct Frame {
	int h;
	int w;
};

int main(void) {
	int a, b;

	vector<struct Frame> v;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}

		struct Frame frm;
		frm.h = a;
		frm.w = b;

		v.push_back(frm);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].h; j++) {
			for (int k = 0; k < v[i].w; k++) {
				if (k == 0 || k == v[i].w - 1 || j == 0 || j == v[i].h - 1) {
					cout << "#";
				}
				else {
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}