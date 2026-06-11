#include<iostream>

using namespace std;

int main() {
	int l, r, d;
	cin >> l >> r >> d;
	int scoa = 0;
	for (int i = d;i <= r;i += d) {
		if (i >= l)scoa++;
	}
	cout << scoa << endl;
}