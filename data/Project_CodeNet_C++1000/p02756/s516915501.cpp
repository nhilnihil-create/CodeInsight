#include <iostream>
#include <deque>
using namespace std;

int main() {
	string s;
	cin >> s;
	deque<char> dq(s.begin(), s.end());
	int Q;
	cin >> Q;
	bool rev = false;
	for (int q = 0; q < Q; q++) {
		int a;
		cin >> a;
		if (a == 1) {
			rev ^= true;
		} else {
			int f;
			char c;
			cin >> f >> c;
			bool back = rev ^ (f == 2);
			if (back) dq.push_back(c);
			else dq.push_front(c);
		}
	}
	if (rev) {
		for (auto itr = dq.rbegin(); itr != dq.rend(); itr++) {
			cout << *itr;
		}
	} else {
		for (char c : dq) cout << c;
	}
	cout << endl;
	return 0;
}