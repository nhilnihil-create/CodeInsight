#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
int main() {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i + j) % 2 == 0)cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
