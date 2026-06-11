#include <iostream>
using namespace std;
main () {
	string str;
	while(cin >> str) {
		int sum = 0;
		for (int i=0; i<str.length(); i++) {
			sum += str[i] - 48;
		}
		if (sum == 0) break;
		cout << sum << endl;
	}
}