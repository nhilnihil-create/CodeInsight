#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	while (getline(cin,s)) {
		if (s == ".") {
			break;
		}
		string ss = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				ss += s[i];
			}
			if (s[i] == ')') {
				ss += s[i];
			}
			if (s[i] == '[') {
				ss += s[i];
			}
			if (s[i] == ']') {
				ss += s[i];
			}
		}
		int a, b;
		a = b = 0;
		stack<int> stk;
		bool hh = true;
		for (int i = 0; i < ss.size(); i++) {
			if (ss[i] == '(') {
				a++;
				stk.push(1);
			}
			if (ss[i] == ')') {
				a--;
				if (!stk.empty()) {
					int c = stk.top();
					stk.pop();
					if (c != 1) {
						hh = false;
						break;
					}
				}
				else {
					hh = false;
					break;
				}
			}
			if (ss[i] == '[') {
				b++;
				stk.push(2);
			}
			if (ss[i] == ']') {
				b--;
				if (!stk.empty()) {
					int c = stk.top();
					stk.pop();
					if (c != 2) {
						hh = false;
						break;
					}
				}
				else {
					hh = false;
					break;
				}
			}
		}
		if (!stk.empty()) {
			hh = false;
		}
		if (hh) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}
