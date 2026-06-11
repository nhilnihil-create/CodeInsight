#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string command;
		cin >> command;
		int a, b;
		cin >> a >> b;
		if (command == "print") {
			for (int j = a; j < b + 1; ++j) {
				cout << str[j];
			}
			cout << endl;
		}
		else if (command == "reverse") {
			string rts = str;
			for (int k = a; k < b + 1; ++k) {
				str[k] = rts[b + a - k];
			}
		}
		else if (command == "replace") {
			string p;
			cin >> p;
			int count = 0;
			for (int l = a; l < b + 1; ++l) {
				str[l] = p[count];
				count++;
			}
		}
	}
	return 0;
}