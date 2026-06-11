#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> blacket;

void init() {
	str.clear();
	while(!blacket.empty())
		blacket.pop();
}

bool input() {
	getline(cin, str);
	if(str.size() == 1 && str[0] == '.')
		return false;

	return true;
}

bool solve() {
	for(int i = 0; i < str.size(); i++) {
		switch(str[i]) {
			case '(':
				blacket.push(str[i]);
				break;
			case '[':
				blacket.push(str[i]);
				break;
			case ')':
				if(blacket.size() > 0 && blacket.top() == '(')
					blacket.pop();
				else
					return false;
				break;
			case ']':
				if(blacket.size() > 0 && blacket.top() == '[')
					blacket.pop();
				else
					return false;
				break;
		}
	}

	if(blacket.size() > 0)
		return false;

	return true;
}

int main() {
	while(init(), input()) {
		if(solve())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	
	return 0;
}