#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		if (s == ".")return 0;
		bool b = true;
		stack<char>l;
		for (int i = 0; i != s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				l.push(s[i]);
			}
			else if (s[i] == ')') {
				if (l.size() == 0)b = false;
				else if (l.top() == '(') {
					l.pop();
				}
				else b = false;
			}
			else if (s[i] == ']') {
				if (l.size() == 0)b = false;
				else if (l.top() == '[') {
					l.pop();
				}
				else b = false;
			}
		}
		if (l.size() != 0)b = false;
		if (b)cout << "yes\n";
		else cout << "no\n";
	}
}