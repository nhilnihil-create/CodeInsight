#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n&&n != 0) {
		int a=0, b=0;
		for (int i = 0; i < n; i++) {
			int c, d;
			cin >> c >> d;
			if (c > d) a += (c + d);
			else if (c < d) b += (c + d);
			else {
				a += c;
				b += c;
			}
		}
		cout << a << " " << b << endl;
	}
}