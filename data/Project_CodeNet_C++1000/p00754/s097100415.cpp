#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;
        stack<char> st;
        st.push('@');
        for (char c : s) {
            if (st.top() == '(' && c == ')') {
                st.pop();
            } else if (st.top() == '[' && c == ']') {
                st.pop();
            } else if (c == '(' || c == '[' || c == ')' || c == ']') {
                st.push(c);
            }
        }
        if ((int)st.size() == 1) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}