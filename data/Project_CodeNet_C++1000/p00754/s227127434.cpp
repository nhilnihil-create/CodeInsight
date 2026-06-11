#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string str;
	stack<char>br;
	while (getline(cin, str), str != ".") {
		int flag = false;
		while (br.empty() != true) br.pop();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') br.push(str[i]);
			else if (str[i] == ')') {
				if (br.empty()) {
					br.push('@');
					break;
				}
				else if ('(' == br.top())br.pop();
				else break;
			}
			else if (str[i] == ']') {
				if (br.empty()) {
					br.push('@');
					break;
				}
				else if ('[' == br.top())br.pop();
				else break; 
			}
		}
		if (br.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}