#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string s;
	int q, t, f;
	char c;
	cin >> s >> q;

	bool rot = 0;
	string front = "";
	string back = "";
	for (int i = 0; i < q; ++i) {
		cin >> t;
		if (t == 1) {
			rot ^= 1;
		}
		else {
			cin >> f >> c;
			if (f == 1) {
				if (rot) {
					back.push_back(c);
				}
				else {
					front.push_back(c);
				}
			} else {
				if (rot) {
					front.push_back(c);
				}
				else {
					back.push_back(c);
				}
			}
		}
	}
	if (rot) {
		reverse(s.begin(), s.end());
		reverse(back.begin(), back.end());
		cout << back + s + front;
	} else {
		reverse(front.begin(), front.end());
		cout << front + s + back;
	}
	return 0;
}