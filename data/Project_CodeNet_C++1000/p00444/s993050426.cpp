#include <iostream>
using namespace std;
int main() {
	int a[6] = { 500,100,50,10,5,1 };
	int b;
	while (cin >> b) {
		if (b == 0)break;
		int c = 0;
		b = 1000 - b;
		for (int i = 0; i < 6; ++i) {
			if (b / a[i]>=1) {
				c = c + b / a[i];
				b = b%a[i];
			}
		}
		cout << c << endl;
	}
	return 0;
}