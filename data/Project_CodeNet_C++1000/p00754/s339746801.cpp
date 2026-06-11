#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		string S; getline(cin, S);
		if(S == ".") break;
		stack<char> stk;
		bool ok = true;
		for(int i = 0; i < (int)S.size(); ++i) {
			if(S[i] == '[') {
				stk.push(S[i]);
			}
			if(S[i] == '(') {
				stk.push(S[i]);
			}
			if(S[i] == ']') {
				if(stk.empty() == false && stk.top() == '[') {
					stk.pop();
				}
				else {
					ok = false;
					break;
				}
			}
			if(S[i] == ')') {
				if(stk.empty() == false && stk.top() == '(') {
					stk.pop();
				}
				else {
					ok = false;
					break;
				}
			}
		}
		if(stk.empty() == false) ok = false;
		cout << (ok ? "yes" : "no") << endl;
	}
}