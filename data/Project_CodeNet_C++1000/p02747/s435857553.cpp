#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	if ((int)S.size()%2 == 1) {
		cout << "No" << endl;
		return 0;
	} else {
		for (int i = 0; i < (int)S.size(); i += 2) {
			if (S.at(i) != 'h' || S.at(i + 1) != 'i') {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
}