#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s;
string input;

int main() {
	bool yes;
	while(1) {
		while(!s.empty()) s.pop();
		yes = true;
		getline(cin,input);
		if (input == ".") break;
		for(int i=0; input[i] != '.'; i++) {
			if(input[i]=='(' || input[i]=='[') s.push(input[i]);
			if(input[i]==')'){
				if(s.empty()) yes = false;
				else if(s.top() == '(') s.pop();
				else yes = false;
			}
			if(input[i]==']'){
				if(s.empty()) yes = false;
				else if(s.top() == '[') s.pop();
				else yes = false;
			}
			//cout << input[i] << ":" << yes << endl;
		}
		if (!s.empty()) yes = false;
		if (yes) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}