#include<iostream>
#include<string>

using namespace std;

int main() {
	bool isOver = false;
	while (!isOver) {
		string s;
		cin >> s;
		if (s[0] == '0') {
			isOver = true;
			break;
		}
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			char temp = s[i];
			int x = temp - 48;
			sum += x;
		}

		cout << sum << endl;
	}

	
	return 0;
}