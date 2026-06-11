#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)


int main() {
	string s;
	while (getline(cin, s), (s != ".")) {
		stack<char> st;
        st.push('a');
		bool ok = true;
		for (char c : s) {
			if (c == '(' || c == '['){ st.push(c); }
			if (c == ')'){ if(st.top() == '(') st.pop(); else ok = false; }
			if (c == ']'){ if(st.top() == '[') st.pop(); else ok = false; }
		}
		cout << (ok && st.size() == 1 ? "yes" : "no") << endl;
	}
}