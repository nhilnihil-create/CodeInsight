#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solve(string s) {
    stack<char> st;
    for (string::iterator i = s.begin(); i != s.end(); i++) {
        switch (*i) {
            case '(':
                st.push('(');
                break;
            case ')':
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
                break;
            case '[':
                st.push('[');
                break;
            case ']':
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
                break;
        }
    }
    if (st.empty()) return true;
    else return false;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;
        if (solve(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}