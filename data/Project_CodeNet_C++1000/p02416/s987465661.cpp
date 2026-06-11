#include <iostream>

using namespace std;

int main() {
	while (1) {
		string s;
		cin >> s;
		int num = s[0] - '0';
		if (num == 0)
			break;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			num = s[i] - '0';
			sum += num;
		}
		cout << sum << endl;
	}

	return 0;
}