#include<iostream>
using namespace std;
int main() {
	int x; cin >> x;
	while (true) {
		for (int i = 2; i <= x; i++) {
			if (i == x) {
				cout << x << endl;
				return 0;
			}
			if (x % i == 0) break;
		}
		x++;
	}
}