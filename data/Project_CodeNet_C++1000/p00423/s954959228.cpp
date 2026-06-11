#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int a;
	while (cin >> a, a) {
		int b = 0, c = 0;
		for (int d = 0; d < a; d++) {
			int e, f;
			cin >> e >> f;
			if (e < f)c += e+f;
			else if (e > f)b += e+f;
			else { b += e; c += f; }
		}
		cout << b << " " << c << endl;
	}
}