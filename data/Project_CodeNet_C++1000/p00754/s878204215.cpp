#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		if (s == ".")break;

		int flg = 1;
		stack<char>st;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '(') {
				st.push(s[i]);
			}
			else if (s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (!st.empty()&&st.top() == '(')st.pop();
				else {
					flg = 0;
					break;
				}
			}
			else if (s[i] == ']'){
				if(!st.empty()&&st.top()=='[') st.pop();
				else {
					flg = 0;
					break;
				}
			}
		}

		if (!st.empty())flg = 0;

		if (flg == 1)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}