#include <iostream>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
	std::string str;
	getline(cin, str);

	while (str[0] != '.' && str.length() != 0) {
		std::stack<int> check;
		bool much = true;
		for (int i = 0; i < str.length()+1; i++) {
			if (much) {
				if (str[i] == '(') {
					check.push(1);
				}
				if (str[i] == ')') {
					if (check.empty()) {
						much = false;
					} else {
						if (check.top()!=1) {
							much = false;
						}
						check.pop();
					}
				}
				if (str[i] == '[') {
					check.push(2);
				}
				if (str[i] == ']') {
					if (check.empty()) {
						much = false;
					} else {
						if (check.top()!=2) {
							much = false;
						}
						check.pop();
					}
				}
			}
		}
		if (much && check.empty()) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
		getline(cin, str);
	}

	return 0;
}