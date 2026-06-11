#include<iostream>
using namespace std;
int main() {
	int i, n;
	for (i = 1; i <= 9; i++) {
		for (n = 1; n <= 9; n++) {
			cout << i << 'x' << n << '=' << i*n << endl;
		}
	}
	return 0;
}