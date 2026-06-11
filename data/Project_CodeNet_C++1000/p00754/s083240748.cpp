#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string input;
	while(1) {
		getline(cin, input);
		if(input == ".") {
			break;
		}

		vector<char> sign;
		for(int i = 0; i < input.size(); i++) {
			if(input[i] == '(') {
				sign.push_back('(');
			}
			if(input[i] == '[') {
				sign.push_back('[');
			}
			if(input[i] == ')') {
				if(sign.empty()) {
					sign.push_back(')');
					break;
				}else if(*(sign.end() - 1) != '(') {
					break;
				}
				sign.pop_back();
			}
			if(input[i] == ']') {
				if(sign.empty()) {
					sign.push_back(']');
					break;
				}else if(*(sign.end() - 1) != '[') {
					break;
				}
				sign.pop_back();
			}
		}

		if(sign.empty()) {
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
	return 0;
}