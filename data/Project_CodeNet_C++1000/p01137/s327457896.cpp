#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int a;
	while (cin >> a, a) {
		int s = 1 << 29;
		for (int x = 0;; x++) {
			if (x*x*x > a)break;
			int y = sqrt(a - x*x*x);
			s = min(s, x + y + a - x*x*x - y*y);
		}
		cout << s << endl;
	}
}