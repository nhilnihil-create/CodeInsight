#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.size() % 2 == 1) {
		cout << "No" << endl;
      return 0;
	}
	else {
		for (int i = 0; i < S.size(); i++) {
			if ((i % 2 == 0 && S[i] != 'h') || (i % 2 == 1 && S[i] != 'i')) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
