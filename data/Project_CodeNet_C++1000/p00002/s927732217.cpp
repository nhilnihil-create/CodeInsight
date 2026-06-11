#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b;
	while(cin >> a >> b) {
		a += b;
		a = (int)log10((double)a) + 1;

		cout << a << endl;
	}
	return 0;
}