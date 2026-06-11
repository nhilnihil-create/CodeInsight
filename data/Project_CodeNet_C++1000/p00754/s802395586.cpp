#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	while(getline(cin,s), s != ".") {
		stack<char> sk;
		bool flg = true;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(' || s[i] == '[') {
				sk.push(s[i]);
			}
			else if(s[i] == ')') {
				if(!(sk.size() && sk.top() == '(')) {
					flg = false;
					break;
				}
				sk.pop();
			}
			else if (s[i] == ']') {
				if(!(sk.size() && sk.top() == '[')) {
					flg = false;
					break;
				}
				sk.pop();
			}
		}
		if(sk.size()) flg = false;

		cout << (flg ? "yes" : "no" ) << endl;
	}
}