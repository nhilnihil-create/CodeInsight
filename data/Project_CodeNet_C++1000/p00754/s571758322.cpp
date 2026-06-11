#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string s;
	while(getline(cin, s), s != ".") {
    stack<char> st;
    st.push('$');
    bool valid = true;
    for (int i = 0; i < s.size() && valid; i++) {
      if (s[i] == '(' || s[i] == '[') {
        st.push(s[i]);
      } else if (s[i] == ')') {
        valid = st.top() == '(';
        st.pop();
      } else if (s[i] == ']') {
        valid = st.top() == '[';
        st.pop();
      }
    }
    valid = valid && st.top() == '$';
    
    cout << (valid ? "yes" : "no") << endl;
    }
    return 0;
}