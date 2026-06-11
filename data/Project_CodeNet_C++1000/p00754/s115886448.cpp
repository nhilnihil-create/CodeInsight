#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (true) {
        string s;
        getline(cin, s);
        if (s[0] == '.') {
            break;
        }

        stack<char> st;
        bool ok = true;
        for (auto&& c : s) {
            if (!ok) {
                break;
            }
            switch (c) {
            case '(':
                st.push(c);
                break;
            case '[':
                st.push(c);
                break;
            case ')':
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    ok = false;
                }
                break;
            case ']':
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    ok = false;
                }
                break;
            }
        }
        if (ok && st.empty()) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}