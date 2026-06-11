#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		char s[101];
		int c;
		int j = 0;
		while (true) {
			c = getchar();
			if (c == '\n') break;
			s[j++] = c;
		}
		s[j] = '\0';
		if (s[0] == '.') return 0;
		
		stack<char> stk;
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == '(') stk.push('(');
			else if (s[i] == '[') stk.push('[');
			else if (s[i] == ')') {
				if (!stk.empty()) {
					if (stk.top() == '(') stk.pop();
					else stk.push(')');
				} else stk.push(')');
			} else if (s[i] == ']') {
				if (!stk.empty()) {
					if (stk.top() == '[') stk.pop();
					else stk.push(']');
				} else stk.push(']');
			}
		}
		
		if (stk.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}