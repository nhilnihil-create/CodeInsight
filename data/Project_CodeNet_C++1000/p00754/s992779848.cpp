#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
	string s;
	while (getline(cin, s), s != ".") {
		stack <char> st;
		bool judge = true;
		rep (i, s.size()) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			if (s[i] == ')' || s[i] == ']') {
				if (st.size() < 1) {
					judge = false;
					continue;
				}
				judge &= s[i] == ')' && st.top() == '('
					  || s[i] == ']' && st.top() == '[';
				st.pop();
			}
		}
		judge &= st.size() == 0;
		cout << (judge ? "yes" : "no") << endl;
	}
	return 0;
}
