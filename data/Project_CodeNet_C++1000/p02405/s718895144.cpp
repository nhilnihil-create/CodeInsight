#include <iostream>
#include <vector>

using namespace std;

class HighWidth {
public:
	int h;
	int w;
	HighWidth() {}
	~HighWidth() {}
};

int main(void) {
	int H, W;

	vector<HighWidth> v;
	while (cin >> H >> W) {
		if (H == 0 && W == 0) {
			break;
		}
		
		HighWidth work;
		work.h = H;
		work.w = W;

		v.push_back(work);
	}

	bool plaidflg;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].h; j++) {
			if (j % 2 == 0) {
				plaidflg = true;
			}
			else {
				plaidflg = false;
			}

			for (int k = 0; k < v[i].w; k++) {
				if (plaidflg) {
					cout << "#";
				}
				else {
					cout << ".";
				}
				plaidflg = !plaidflg;
			}

			cout << endl;
		}
		cout << endl;
	}

	return 0;
}