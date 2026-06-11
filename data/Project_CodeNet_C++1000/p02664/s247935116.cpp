#include <iostream>
#include <string>
using namespace std;

string T;

int main(void) {
	cin >> T;

	for (int i = 0; i < (int)T.length(); ++i) {
		if (T[i] == '?')
			T[i] = 'D';
	}

	cout << T << '\n';
	return 0;
}
