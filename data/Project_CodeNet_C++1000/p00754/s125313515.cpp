#include<iostream>
#include<stack>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  string str;
  while (true) {
    getline(cin, str);
    if (str == ".") break;
    stack<char> st;
    bool ok = true;
    rep (i, str.size()) {
      if (str[i] == '(') st.push('(');
      if (str[i] == '[') st.push('[');
      if (str[i] == ')') {
	if (st.empty()) {
	  ok = false;
	  break;
	}
	char c = st.top();
	st.pop();
	if (c != '(') {
	  ok = false;
	  break;
	}
      }
      if (str[i] == ']') {
	if (st.empty()) {
	  ok = false;
	  break;
	}
	char c = st.top();
	st.pop();
	if (c != '[') {
	  ok = false;
	  break;
	}
      }
    }
    if (!st.empty()) ok = false;
    if (ok) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}