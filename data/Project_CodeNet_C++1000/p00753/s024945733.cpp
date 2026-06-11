#include <iostream>
using namespace std;


bool p[247000] = { false };

int main(){
	p[0] = p[1] = true;
	for (int i = 2; i < 247000; i++) {
		if (!p[i]) {
			for (int j = 2; j*i < 247000; j++) {
				p[i*j] = true;
			}
		}
	}
	int n, c;
	while (cin >> n && n != 0) {
		c = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!p[i]) {
				c++;
			}
		}
		cout << c << endl;
	}

	return 0;
}