#include <iostream>
using namespace std;
int main() {
	long long int x,a=0;
	cin >> x;
	for (int i = 0; x >= 500; i++) {
		a += 1000;
		x -= 500;
	}
	for (int i = 0; x >= 5; i++) {
		a += 5;
		x -= 5;
	}
	cout << a;
}