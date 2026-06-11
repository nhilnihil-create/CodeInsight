#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

int main() {
	string str;
	while (1) {
		getline(cin, str);
		if (str == ".") break;

		stack<char> stk;
		bool flag = true;
		REP(i, 0, str.size()) {
			if (str[i] == '(' || str[i] == '[') stk.push(str[i]);
			else if (str[i] == ')') {
				if (stk.empty()) {
					flag = false;
					break;
				}
				
				char c = stk.top();
				stk.pop();
				if (c != '(') {
					flag = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (stk.empty()) {
					flag = false;
					break;
				}

				char c = stk.top();
				stk.pop();
				if (c != '[') {
					flag = false;
					break;
				}
			}
		}

		if (flag && stk.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}