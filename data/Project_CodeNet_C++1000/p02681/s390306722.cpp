#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i;
	string S, T;
	cin >> S >> T;
	int x = S.length();
	int y = T.length();
	int a = 0;
	if (y == x + 1) {
		for (i = 0; i < x; i++) {
			if (S[i] != T[i]) {
				a += 1;
			}
		}
		if (a == 0) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	else {
		cout << "No" << "\n";
	}
}