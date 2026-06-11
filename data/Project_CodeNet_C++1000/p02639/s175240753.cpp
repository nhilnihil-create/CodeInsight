#include<iostream>
using namespace std;

int main() {
	for (int i = 1; i < 6; i++) {
		int x;
		cin >> x;
		if (x != i) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}