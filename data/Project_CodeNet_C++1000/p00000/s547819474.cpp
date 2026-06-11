#include <iostream>
#include <cmath>

#define SIZE 9

using namespace std;

void trace(int, int);

int main(void) {
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			trace(i, j);
		}
	}
	return 0;
}

void trace(int a, int b) {
	cout << a << "x" << b << "=" << a*b << "\n";
}