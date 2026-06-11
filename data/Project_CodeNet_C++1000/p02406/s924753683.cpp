#include<iostream>
using namespace std;

void call(int n) {
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			cout << " " << i;
		}
		else if (i % 10 == 3) {
			cout << " " << i;
		}
		else if (i / 10 == 3) {
			cout << " " << i;
		}
		else if ((i / 10) % 10 == 3) {
			cout << " " << i;
		}
		else if ((i / 100) % 10 == 3) {
			cout << " " << i;
		}
		else if ((i / 1000) % 10 == 3) {
			cout << " " << i;
		}
		else if ((i / 10000) % 10 == 3) {
			cout << " " << i;
		}
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	call(n);

}
