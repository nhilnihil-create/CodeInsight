#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		for (int i = 1; i <= a; i++) {
			if (i==1||i==a){
				for (int j = 1; j <= b; j++) {
					cout << "#";
				}
				cout << endl;
			}
			else {
				cout << "#";
				for (int j = 1; j <= b-2; j++) {
					cout << ".";
				}
				cout << "#" << endl;
			}
		}
		cout << endl;
	}

	return 0;
}