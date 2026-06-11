#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

struct Dice {
	Dice() { d = new int[6]; }
	~Dice() { delete[] d; }

	void get() {
		for (int i = 0; i < 6; i++) {
			cin >> d[i];
		}
	}
	void roll(char c) {
		int t = d[0];
		int tmp = d[1];
		switch (c) {
		case 'N':
			d[0] = d[1]; d[1] = d[5]; d[5] = d[4]; d[4] = t;
			break;
		case 'S':
			d[0] = d[4]; d[4] = d[5]; d[5] = d[1]; d[1] = t;
			break;
		case 'W':
			d[0] = d[2]; d[2] = d[5]; d[5] = d[3]; d[3] = t;
			break;
		case 'E':
			d[0] = d[3]; d[3] = d[5]; d[5] = d[2]; d[2] = t;
			break;
		case 'r':
			d[1] = d[2]; d[2] = d[4]; d[4] = d[3]; d[3] = tmp;
			break;
		default:
			break;
		}
	}
	int top() { return d[0]; }
	int right() { return d[2]; }
	int front() { return d[1]; }
	int left() { return d[3]; }
	Dice & operator=(Dice & obj) { this->d = obj.d; }
	int* d;
};

int main() {
	Dice d;
	d.get();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (d.left() == l) { d.roll('E'); }
		if (d.right() == l) { d.roll('W'); }
		while (d.top() != l) { d.roll('N'); }
		while (d.front() != r) { d.roll('r'); }
		cout << d.right() << endl;
	}
	return 0;
}

