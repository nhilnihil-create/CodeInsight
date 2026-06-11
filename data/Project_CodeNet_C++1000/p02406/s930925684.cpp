#include<iostream>

using namespace std;

void nabeatsu(int n) {
	int x;
	for (int i = 1; i <= n; i++) {
		x = i;
		if (x % 3 == 0) {
			cout << " " << i;
		}
		else if (x % 10 == 3) {
			cout << " " << i;
		}
		else {
			x /= 10;
			if (x % 10 == 3) {
				cout << " " << i;
			}
			else if (x/10 % 10 == 3) {
				cout << " " << i;
			}
			else if (x/100 % 10 == 3) {
				cout << " " << i;
			}
		}
		
	}
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	nabeatsu(n);
	return 0;
}