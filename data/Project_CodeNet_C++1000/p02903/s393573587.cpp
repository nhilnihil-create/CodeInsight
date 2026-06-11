#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << (i < b ^ j < a);
		}
		cout << endl;
	}
}
